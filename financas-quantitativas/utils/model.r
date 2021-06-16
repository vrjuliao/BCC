 #########################
 # models.r              #
 #                       # 
 # Copyright(c) 2020     #
 # Cristiano Arbex Valle #
 # All rights reserved.  #
 #########################


###################################
### Auxiliary functions
printf <- function(...) invisible(cat(sprintf(...)))

exit <- function() {
  .Internal(.invokeRestart(list(NULL, NULL), NULL))
}

stop0 <- function(...) stop(..., call.=FALSE);

loadPackage <- function(package) {
    checkPackage(package);
    suppressMessages(library(package, character.only = TRUE));
}

checkPackage <- function(package) {
    if (!package %in% rownames(installed.packages())) {
        install.packages(package);
    }
}
###################################



initialiseModel <- function() {
    loadPackage("hash");
    model <- OptimisationModel$new();
    model$initialise();
    return (model);
}


OptimisationModel <- setRefClass("OptimisationModel", 
    
    fields = list(
        
        # Identifier
        numVariables      = "numeric",
        variables         = "character",
        coefficients      = "numeric",
        lower             = "numeric",
        upper             = "numeric",
        varIndex          = "ANY",
        binaryVariables   = "numeric",
        integerVariables  = "numeric",
        
        # matrix for quadratic programming
        quadMatrix        = "matrix",
        
        # Constraints
        numConstraints    = "numeric",
        sense             = "character",
        rhs               = "numeric",
        constraintsNames  = "character",
        constraints       = "matrix",
        # Constraints use sparse matrix notation. It is a matrix of 3 
        # columns, each containing
        #    Constraint index | Variable index | Coefficient value
        
        # min or max
        direction         = "character",
        
        # Solver parameters, none work with quadratic programming
        timeLimit         = "numeric",
        presolve          = "numeric",
        solverDebug       = "numeric",
        
        # If modelFilename is different from an empty string, the
        # model is written into into the given file. 
        # Must have .lp extension. 
        # Note that if quadratic programming is used, the quadratic matrix
        # in the objective function is not written.
        modelFilename     = "character", 
        
        # Solution vectors
        solution          = "numeric",
        solutionExists    = "numeric",
        objValue          = "numeric",
        solverTime        = "numeric",
        status            = "character",
        
        # Controls which solver
        # If quad matrix is provided, then useQuadratic
        # is automativally set and useGLPK is ignored
        # If not, useGLPK = 1 uses GLPK solver
        #         useGLPK = 0 uses lpSolve solver
        useQuadratic      = "numeric",
        useGLPK           = "numeric"
    ),

    methods = list(

################
# Methods (non idented with the definition of the class)

initialise = function() {
    timeLimit        <<- 120;
    modelFilename    <<- "";
    
    useQuadratic     <<- 0;
    useGLPK          <<- 1;

    numVariables     <<- 0;
    variables        <<- character(0);
    coefficients     <<- numeric(0);
    lower            <<- numeric(0);
    upper            <<- numeric(0);
    varIndex         <<- hash();
    binaryVariables  <<- numeric(0);
    integerVariables <<- numeric(0);
    numConstraints   <<- 0;
    constraintsNames <<- character(0);
    sense            <<- character(0);
    rhs              <<- numeric(0);
    constraints      <<- matrix(0, nrow = 0, ncol = 3);
    direction        <<- "min";
    
    # Solver parameters
    # Do not work with quadratic programming
    presolve         <<- 0;
    solverDebug      <<- 0;
    
    # Matrix for quadratic programming, i.e. covariance matrix
    quadMatrix       <<- matrix(0, nrow = 0, ncol = 0);
    
    status         <<- "";
    solution       <<- rep(0, numVariables);
    objValue       <<- 0;
    solutionExists <<- 0;
    solverTime     <<- 0; 
}, 

getVariableValue = function(name) {
    ind = varIndex[[name]];
    return (solution[ind]);
},

setTimeLimit = function(tl) {
    timeLimit <<- tl;
},

setModelFilename = function(filename) {
    if (filename != "" && !endsWith(filename, ".lp")) stop0(sprintf("In setModelFilename, model name must finish with .lp (you gave %s)", filename));
    modelFilename <<- filename;
},

setDirection = function(isMax) {
    if (isMax) {
        direction <<- "max";
    } else {
        direction <<- "min";
    }
},

setPresolve = function(usePresolve) {
    if (usePresolve) {
        presolve <<- 1;
    } else {
        presolve <<- 0;
    }
},

setSolverDebug = function(sd) {
    if (sd) {
        solverDebug <<- 1;
    } else {
        solverDebug <<- 0;
    }
},


addBinaryVariable = function(name = NULL, coefficient = 0) {
    if (useQuadratic) {
        stop0("The model is already set to quadratic, and at the moment we cannot solve quadratic models with binary/integer variables.");
    }
    if (is.null(name)) stop0("In addBinaryVariable, variable name must be provided");
    if (!is.numeric(coefficient)) stop0("In addBinaryVariable, coefficient must be a numeric value.");
    name = as.character(name);
    if (has.key(name, varIndex)) stop0(sprintf("Model already has a variable called %s", name));
    numVariables     <<- numVariables + 1;
    variables        <<- c(variables, name);
    coefficients     <<- c(coefficients, coefficient);
    lower            <<- c(lower, 0);  
    upper            <<- c(upper, 1);  
    varIndex[name]   <<- numVariables;
    binaryVariables  <<- c(binaryVariables , numVariables);
},

addIntegerVariable = function(name = NULL, coefficient = 0, low = -Inf, up = Inf) {
    if (useQuadratic) {
        stop0("The model is already set to quadratic, and at the moment we cannot solve quadratic models with binary/integer variables.");
        return (0);
    }
    if (is.null(name)) stop0("In addIntegerVariable, variable name must be provided");
    if (!is.numeric(coefficient)) stop0("In addIntegerVariable, coefficient must be a numeric value.");
    if (!is.numeric(low)) stop0("In addIntegerVariable, low (lower bound) must be a numeric value.");
    if (!is.numeric(up )) stop0("In addIntegerVariable, up (upper bound) must be a numeric value.");
    name = as.character(name);
    if (has.key(name, varIndex)) stop0(sprintf("Model already has a variable called %s", name));
    if (low > up) stop0(sprintf("In addIntegerVariable for variable %s, the lower bound must be greater than the upper bound.", name));
    numVariables     <<- numVariables + 1;
    variables        <<- c(variables, name);
    coefficients     <<- c(coefficients, coefficient);
    lower            <<- c(lower, low);  
    upper            <<- c(upper, up);  
    varIndex[name]   <<- numVariables;
    integerVariables <<- c(integerVariables, numVariables);
},



addVariable = function(name = NULL, coefficient, low = -Inf, up = Inf) {
    if (is.null(name)) stop0("In addVariable, variable name must be provided");
    if (!is.numeric(coefficient)) stop0("In addVariable, coefficient must be a numeric value.");
    if (!is.numeric(low)) stop0("In addVariable, low (lower bound) must be a numeric value.");
    if (!is.numeric(up )) stop0("In addVariable, up (upper bound) must be a numeric value.");
    name = as.character(name);
    if (has.key(name, varIndex)) stop0(sprintf("Model already has a variable called %s", name));
    if (low > up) stop0(sprintf("In addVariable for variable %s, the lower bound must be greater than the upper bound.", name));
    if (useQuadratic) {
        stop0("You already provided a quadratic matrix. You cannot add variables to the problem after providing the quadratic matrix.");
    }
    
    numVariables   <<- numVariables + 1;
    variables      <<- c(variables, name);
    coefficients   <<- c(coefficients, coefficient);
    lower          <<- c(lower, low);  
    upper          <<- c(upper, up);  
    varIndex[name] <<- numVariables;
},

addConstraint = function(s, b, elements, values, name = "") {
    if (s != ">=" && s != "<=" && s != "=") stop0("Error in sense in addConstraint, should be >=, <= or =.");
    if (length(elements) == 0) stop0("In addConstraint, no variables were provided.");
    if (length(elements) != length(values)) stop0("In addConstraint, vectors elements and values must have the same size.");
    if (!is.numeric(values)) stop0("Values must be a numeric vector\n");
    if (anyDuplicated(elements)) stop0("In addConstraint, there are duplicated names in the elements vector.");
    elements = as.character(elements);
    for (i in 1 : length(elements)) {
        if (!has.key(elements[i], varIndex)) stop0(sprintf("In addConstraint, you provided variable %s which does not exist.", elements[i]));
    }
    numConstraints <<- numConstraints + 1;
    sense          <<- c(sense, s);
    rhs            <<- c(rhs  , b);
    if (name == "") name = paste("Constraint", numConstraints);
    constraintsNames <<- c(constraintsNames, name);
    el = numeric(length(elements));
    for (i in 1 :length(el)) {
        el[i] = varIndex[[elements[i]]];
    }
    m = matrix(numConstraints, ncol = 3, nrow = length(values));
    m[,2] = el;
    m[,3] = values;
    constraints <<- rbind(constraints, m);
    return(numConstraints);
},

addQuadraticMatrix = function(quadraticMatrix = matrix(0, ncol = 0, nrow = 0)) {
    if (length(binaryVariables) > 0 || length(integerVariables) > 0) {
        stop0("For the moment it is impossible to solve a mixed-integer quadratic program. The model\n already has binary or integer variables, so you cannot set a quadratic matrix.");
    }
    
    if (!is.matrix(quadraticMatrix)) stop0("In addQuadraticMatrix, quadraticMatrix must be a matrix.");
    if (nrow(quadraticMatrix) != length(variables)) stop0("In addQuadraticMatrix, the number of rows in the matrix must be equal to the length of the variables vector.");
    if (ncol(quadraticMatrix) != nrow(quadraticMatrix)) stop0("In addQuadraticMatrix, you have to provide a square matrix.");
    
    quadMatrix <<- quadraticMatrix;
    useQuadratic <<- 1;
},

getSolutionValue = function(var) {
    if (!solutionExists) stop0("In getSolutionValue, a solution does not exist, either because the model was not solved or because the model couldn't find a solution.");
    if (!has.key(var, varIndex)) stop0(sprintf("In getSolutionValue, there is no variable %s.", var));
    
    return (solution[varIndex[[var]]]);
},


createLPModel = function() {

    loadPackage("lpSolveAPI");
    lpmodel = make.lp(nrow = numConstraints, ncol = numVariables);
    if (length(binaryVariables ) > 0) set.type(lpmodel, binaryVariables,  "binary");
    if (length(integerVariables) > 0) set.type(lpmodel, integerVariables, "integer");
    for (i in 1 : numVariables) {
        m = constraints[constraints[, 2] == i, , drop = FALSE];
        if (nrow(m) > 0) {
            set.column(lpmodel, i, x = m[,3], indices = m[,1]);
        }
    }
    if (numConstraints > 0) {
        set.constr.type (lpmodel, sense, 1:numConstraints);
        set.constr.value(lpmodel, rhs, lhs = NULL, 1:numConstraints);
    }

    set.objfn(lpmodel, coefficients);
    set.bounds(lpmodel, lower, upper);
    lp.control(lpmodel, sense = direction);
    lp.control(lpmodel, timeout = timeLimit);
    if (presolve) lp.control(lpmodel, presolve = c("probefix", "probereduce", "rows", "cols", "lindep", "rowdominate", "coldominate"));
    if (solverDebug) lp.control(lpmodel, verbose = "normal");

    if (modelFilename != "") {
        dimnames(lpmodel) = list(constraintsNames, variables);
        write.lp(lpmodel, modelFilename, type = "lp");
        printf("Optimisation model exported to file %s \n   in folder %s\n\n", modelFilename, getwd());
    }
    
   
},

solveWithRglpk = function () {
    loadPackage("Rglpk");
    
    type = rep("C", numVariables);
    if (length(integerVariables) > 0) type[integerVariables] = "I";
    if (length(binaryVariables ) > 0) type[binaryVariables ] = "B";
    m = TRUE;
    if (direction == 0) m = FALSE;
    control = list(tm_limit = timeLimit*1000, canonicalize_status = FALSE);
    if (solverDebug) control$verbose  = TRUE;
    if (presolve   ) control$presolve = TRUE;
    sense[sense == "="] <<- "==";
    mat = simple_triplet_matrix(constraints[,1], constraints[,2], constraints[,3]);
          
    TIME = proc.time();
    sol =  Rglpk_solve_LP(obj      = coefficients,
                          mat      = mat,
                          dir      = sense,
                          rhs      = rhs,
                          bounds   = list(lower = list(ind = seq(1, numVariables), val = lower),
                                          upper = list(ind = seq(1, numVariables), val = upper)),
                          types   = type,
                          max     = m,
                          control = , control);
    solverTime <<- (proc.time() - TIME)[3];
    
    val = sol$status;
    solution <<- rep(0, numVariables);

    if (val == 5) {
        status         <<- "Optimal solution";
        solution       <<- sol$solution;
        objValue       <<- sol$optimum;
        solutionExists <<- 1;
    } else if (val == 2) {
        status         <<- "Non-optimal solution";
        solution       <<- sol$solution;
        objValue       <<- sol$optimum;
        solutionExists <<- 1;
    } else if (val == 4 || val == 3) {
        status   <<- "No solution exists, the model is infeasible";
    } else if (val == 1) {
        status   <<- "The time limit was reached before a solution could be found";
    } else {
        status   <<- "No solution exists, the model is undefined";
    }

},

solveWithLPSolve = function(justPrint = 0) {
        
    lpmodel = createLPModel();
    
    if (justPrint) {
        print(lpmodel);
        rm(lpmodel);
        return(0);
    }

    TIME = proc.time();
    val = solve.lpExtPtr(lpmodel);
    solverTime <<- (proc.time() - TIME)[3];
    
    solution <<- rep(0, numVariables);
    if (val == 0 || val == 9) {
        status         <<- "Optimal solution";
        sol              = get.primal.solution(lpmodel, orig = TRUE);
        solution       <<- sol[(length(sol)-numVariables+1):length(sol)]
        objValue       <<- get.objective(lpmodel);
        solutionExists <<- 1;
    } else if (val == 1 || val == 12) {
        status         <<- "Non-optimal solution";
        sol              = get.primal.solution(lpmodel, orig = TRUE);
        solution       <<- sol[(length(sol)-numVariables+1):length(sol)]
        objValue       <<- get.objective(lpmodel);
        solutionExists <<- 1;
    } else if (val == 7) {
        status   <<- "The time limit was reached before a solution could be found";
    } else {
        status   <<- "No solution exists, the model is infeasible";
    }
    rm(lpmodel);

}, 

updateConstraintMatrixIfQuadratic = function() {
    
    n  = numConstraints;
    cs = constraints;
    nm = constraintsNames;
    ss = sense;
    rh = rhs;

    ###################################
    ## Add bounds as constraints
    for (i in 1 : numVariables) {
        if (lower[i] > -Inf) {
            n  = n + 1;
            cs = rbind(cs, c(n, i, 1));
            ss = c(ss, ">=");
            rh = c(rh, lower[i]);
            nm = c(nm, paste0("variableLB", i));
        }
        if (upper[i] < Inf) {
            n  = n + 1;
            cs = rbind(cs, c(n, i, 1));
            ss = c(ss, "<=");
            rh = c(rh, upper[i]);
            nm = c(nm, paste0("variableUB", i));
        }
    }
    ###################################

    ###################################
    ## Change all <= constraints to >=
    for (i in 1 : nrow(cs)) {
        if (ss[cs[i,1]] == "<=") {
            cs[i,3] = -cs[i,3];
        }
    }
    lessOrEqual = ss == "<=";
    rh[lessOrEqual] = -rh[lessOrEqual];
    ss[lessOrEqual] = ">=";
    ###################################
   
    ###################################
    ## Move equality constraints to the beginning
    count = 1;
    newIndices = rep(0, n);
    for (i in 1 : n) {
        if (ss[i] == "=") {
            newIndices[i] = count;
            count = count + 1;
        }
    }
    for (i in 1 : n) {
        if (newIndices[i] == 0) {
            newIndices[i] = count;
            count = count + 1;
        }
    }
    nm = nm[newIndices];
    ss = ss[newIndices];
    rh = rh[newIndices];
    
    for (i in 1 : nrow(cs)) {
        cons = cs[i,1]
        cs[i,1] = newIndices[cons];
    }
    cs = cs[order(cs[,1]),]
    #################################


    numConstraints   <<- n;
    constraints      <<- cs;
    constraintsNames <<- nm;
    sense            <<- ss;
    rhs              <<- rh;
},

solveWithQuadprog = function() {
    
    loadPackage("quadprog");
    Dmat = quadMatrix;
    dvec = coefficients;
    bvec = rhs;
    meq  = sum(sense == "=");
    
    if (direction == "max") {
        dvec = -dvec;
        Dmat = -Dmat;
    }
    # TODO I did not manage to make solve.QP.compact work properly
    #      The documentation suggests matrix A is constraints x variables
    #      If suggests a compact format where Aind constraints the number of
    #        non zero elements per variable
    #      However that does not work since the model solves A^t b >= b0
    #      I don't know how to express it.
    #
    #
    #mostFrequent = as.numeric(sort(table(constraints[,2]),decreasing=TRUE)[1]);
    #Aind = matrix(0, ncol = numVariables, nrow = mostFrequent + 1);
    #Amat = matrix(0, ncol = numVariables, nrow = mostFrequent);
    #for (i in 1 : numVariables) {
    #    cn = constraints[constraints[,2] == i, ];
    #    num = nrow(cn);
    #    Aind[1,i] = num;
    #    Aind[2:(1+num), i] = cn[,1];
    #    Amat[1:num    , i] = cn[,3];
    #}
    #sol = solve.QP.compact(Dmat = Dmat, dvec = dvec, Amat = Amat, Aind = Aind, bvec = bvec, meq = meq);

    AmatFull = matrix(0, nrow = numConstraints, ncol = numVariables);
    for (i in 1 : nrow(constraints)) {
        AmatFull[constraints[i,1], constraints[i,2]] = constraints[i,3];
    }
    
    TIME = proc.time();
    sol = tryCatch( {
        solve.QP(Dmat = Dmat, dvec = dvec, Amat = t(AmatFull), bvec = bvec, meq = meq);
    }, error = function(e) {
        NULL;
    });
    solverTime <<- (proc.time() - TIME)[3];
    
    if (is.null(sol)) {
        status   <<- "No solution exists, the model is infeasible";
    } else {
        status         <<- "Optimal solution";
        solution       <<- sol$solution;
        objValue       <<- sol$value;
        solutionExists <<- 1;
    }
    
},

solve = function(justPrint = 0) {
    
    if (useQuadratic) {
        updateConstraintMatrixIfQuadratic();
    }

    if (modelFilename != "") {
        lpmodel = createLPModel();
        rm (lpmodel);
        if (useQuadratic) printf("Note: the exported model does not contain the quadratic term in the objective function.\n");
    }
    if (useQuadratic) {
        solveWithQuadprog();
    } else {
        if (useGLPK) {
            solveWithRglpk();
        } else {
            solveWithLPSolve();
        }
    }
}

));


