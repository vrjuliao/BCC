## @ Cristiano
## This is a little wrapper I did for my teaching classes to facilitate generating graphics with
## with ggplot2

# Custom colours vectors that can be used with the option "colours" below
colours1  = c("#0000FF", "#000000", "#FF0000", "#00CC00", "#FFB300", "#CC0066", "#606060", "#99CCFF");
colours2  = c("#0000FF", "#FF0000", "#000000", "#00CC00", "#FFB300", "#CC0066", "#606060", "#99CCFF");
colours3  = c("#FF0000", "#00FF00", "#000000", "#FF0000", "#00CC00", "#FFB300", "#CC0066", "#606060", "#99CCFF");
colours4  = c("#FF0000", "#000000", "#00FF00", "#FF0000", "#00CC00", "#FFB300", "#CC0066", "#606060", "#99CCFF");

getGGOptions <- function() {
    ggOptions <- list(
       

        #####################
        ### TYPE OF GRAPH ###
        # Include line chart
        lineChart   = 0,
        # Bar chart for discrete data
        barChart    = 0,
        # Include histogram of data
        histogram   = 0,
        # Include density of data
        density     = 0,
        # Include points
        scatterplot = 0,
        # Include points
        qqplot      = 0,
        # Autocorrelation function
        acf         = 0,
        # Polygon
        polygon     = 0,
        # Add path 
        addPath     = 0,
        #####################
        # Path is similar to lineChart, but there is one important difference:
        # Line connects the points according to their sorted x values
        # Path connects the points in the order given.

        #####################
        # If the values below are 1, then any line and path (if lineChart = 1 or 
        # addPath = 1) will use the colours, size, etc., provided by other options.
        # If the value below is zero, then the line/path will use default options.
        lineInheritAesthetics = 1,
        pathInheritAesthetics = 0,
        # Line before points - if line/path and scatterplot together, then which is below the other?
        lineBelowPoints       = 0,
        # Connect all observations into a single path regardless of categories.
        singlePath            = 0,
        #####################

        #################
        ### PLOT AREA ###
        # Plot area has white background as opposed to default gray.
        whiteBackground   = 1,
        # Plot area has or hasn't grid lines
        removeGridLines   = 0, # TODO maybe remove minor and major grid lines separately
        #################
        
        #################
        ### LINE PLOT ###
        lineSize          = 1.2,
        # If function is step function, then one must give probabilities
        stepFunction      = 0,
        # Normalise different data vectors so they all start at 1
        normalise         = 0,
        #################

        ###################################
        ### TITLES AND TEXT AROUND PLOT ###
        # Main title of plot
        title             = "",
        # Size of the main title font
        titleSize         = 18,
        # Title of Y axis
        yTitle            = "",
        # Title of X axis
        xTitle            = "",   
        # Size of font of Y and X axis labels
        axisLabelSize     = 16,   
        axisXLabelSize    = 0,
        axisYLabelSize    = 0,   
        # Label rotation
        axisXLabelAngle   = 0,
        axisYLabelAngle   = 0,
        # Set this between 0 and 1 if vertical text stays on top of the axis 
        axisXLabelVJust   = 0.5,
        # Size of font of Y and X axis titles
        axisTitleSize     = 18,
        # Whether Y and X axis titles are bold or not
        axisTitleBold     = 0, 
        ###################################
        
        ####################################
        ### VALUES AND SPACING OF X AXIS ###
        # Remove spacing between plot area and extremes of x axis
        removeXAxisSpace  = 1,
        # Axis values are percentages
        percentageInXAxis = 0,
        # Vector of breaks, equivalent to labels that show up in X axis
        # If NULL ggplot does it automatically
        xAxisBreaks       = NULL,
        # Limits of X axis, it must be either null or vector or two numbers
        xAxisLimits       = NULL,
        # Whether to reverse the X axis or not
        reverseXAxis      = 0,
        # Formats the X axis as date, if the date given are not in th
        # numerical format YYYYMMDD then you may need to also set the
        # dateFormat accordingly.
        formatXAxisAsDate = 0,       
        dateFormat        = "%Y%m%d",
        removeWeekends    = 0,
        ###################################
        
        ####################################
        ### VALUES AND SPACING OF Y AXIS ###
        # Remove spacing between plot area and extremes of x axis
        removeYAxisSpace  = 0,        
        # Axis values are percentages
        percentageInYAxis = FALSE, 
        # Vector of breaks, equivalent to labels that show up in Y axis
        # If NULL ggplot does it automatically
        yAxisBreaks       = NULL,
        # Limits of Y axis, it must be either null or vector of two numbers
        yAxisLimits       = NULL,   
        ###################################

        #######################
        ### COLOURS OF PLOT ###
        # If 1 then plot is black and white
        blackAndWhite     = 0,
        # Use colours defined in colours vectors 1, 2, 3, 4 above
        colours           = 1,
        # If this vector has enough colours, override the vectors above.
        customColours     = character(0),
        #######################
        
        ##############################
        ### TYPES OF LINES IN PLOT ###
        # If all lines are solid of if different line types will be used.
        useLineTypes      = 0,
        # If useLineTypes = 1, ggplot uses its default line types, or you can
        # define them as a vector below. 
        # Example: ggOptions$customLineTypes = c("solid", "dashed");
        customLineTypes   = character(0),
        ##############################
       
        #########################
        ### PLOT AREA MARGINS ###
        # Use default ggplot margins
        changeMargin      = 0,
        # If not default then this vector must have 4 numbers
        margins           = c(0.1, 0.1, 0, 0), # in cm  
        #########################
        
        #############
        ## LEGEND ###
        # add legend or not
        addLegend         = 0,
        # legend position on the plot, if inside the graphic do c(1, 1) for instance
        legendPosition    = "right",
        # Title of legend
        legendTitle       = "",
        # Size of legend font
        legendSize        = 0,
        # Width of legend key, applied only if greater than zero
        legendKeyWidth    = 0,
        # Width of legend key, applied only if greater than zero
        legendTextSize    = 10,
        # Vector with legend values
        legend            = character(),
        #############
        
        ######################
        ### VERTICAL LINES ###
        # Add vertical line(s) or not
        addVerticalLine   = 0,
        # X value of vertical lines
        # If the sizes, colours and types have length 1, all
        # lines will have the same properties.
        verticalLines     = c(0),
        # Line width of vertical lines
        verticalSizes     = c(0.2),
        # Line colours of vertical lines
        verticalColours   = c("black"),
        # Line types of vertical lines
        verticalTypes     = c("solid"),
        ######################

        ########################
        ### HORIZONTAL LINES ###
        # Add horizontal line(s) or not
        addHorizontalLine = 0,
        # X value of horizontal lines
        # If the sizes, colours and types have length 1, all
        # lines will have the same properties.
        horizontalLines   = c(0),
        # Line width of horizontal lines
        horizontalSizes   = c(0.2),
        # Line colours of horizontal lines
        horizontalColours = c("black"),
        # Line types of horizontal lines
        horizontalTypes   = c("solid"),
        ########################
        
        ################
        ### AB LINES ###
        # add AB lines or not
        addABLine         = 0,
        # Slopes and intercepts of ablines
        abSlope           = c(1),
        abIntercept       = c(0),
        # Features of ablines
        abSizes           = c(0.2),
        abColours         = c("black"),
        abTypes           = c("solid"),
        ################

        ################
        ### SEGMENTS ###
        # Add segments or not
        addSegments       = 0,
        # X and Y begin and end of segments
        segXBegin         = numeric(),
        segXEnd           = numeric(),
        segYBegin         = numeric(),
        segYEnd           = numeric(),
        # Colours of segments
        segColour         = character(),
        segLineSize       = character(),
        segLineType       = character(),
        ################

        ################
        ### EXTRA POINTS ###
        addExtraPoints  = 0,
        extraPointsX    = numeric(0),
        extraPointsY    = numeric(0),
        # Features of extra points
        extraPointsColours = "blue",
        extraPointsFills   = "blue", 
        extraPointsShapes  = 21, 
        extraPointsSizes   = 3,
        ################

        ###############
        ### POLYGON ###
        # Colour of contour lines
        polygonLineColour = c("black"),
        # Colour of feasible region
        polygonFillColour = c("gray"),
        # Type of line (1 = solid)
        polygonLineType   = 1,
        # Width of contour lines
        polygonLineWidth  = 0.5,
        # Opacity of fill colour
        polygonAlpha  = 0.5,
        ###############

        #######################
        ### SHADE INTERVALS ###
        shadeAreaBegin   = numeric(0),
        shadeAreaEnd     = numeric(0),
        shadeAreaColour  = c("red"),
        shadeAreaOpacity = c(0.5),
        # Does not work with multiple shades, for that use SHADED AREAS below
        #######################
        

        #######################
        ### SHADED AREAS    ###
        howManyShadedAreas = 0,
        shadedAreaPoints   = list(),
        shadedAreaColour   = character(0),
        shadedAreaOpacity  = numeric(0),
        #######################
        

        #######################
        ## RECTANGLES       ###
        # Note: if x1 = x2 or y1 = y2 rectangle will not be displayed.
        addRectangles        = 0,
        rectanglesX1         = numeric(0),
        rectanglesY1         = numeric(0),
        rectanglesX2         = numeric(0),
        rectanglesY2         = numeric(0),
        rectanglesLineWidth  = numeric(0),
        rectanglesLineType   = character(0),
        rectanglesLineColour = NA,
        rectanglesFillColour = character(0),
        rectanglesOpacity    = numeric(0),
        rectanglesInTheBack  = numeric(0),
        #######################

        ################################
        ### SAVING IMAGE AS PDF FILE ###
        # If 1 save figure (formats allowed pdf or png), 0 the figure is displayed in RStudio and not saved
        saveGraphics      = 0,
        # DPI quality
        dpi               = 300,
        # Image file name, with .pdf or .png extension
        imageName         = "temp.pdf",
        # Image width in inches
        width             = 12.0,
        # Image height in inches
        height            = 7.06,
        ################################
        
        ###########################
        ### POINT OPTIONS ###
        # Point size
        pointSize         = 3,
        # Point shapes, can be defined manually in customShapes
        useShapes         = 0,
        customShapes      = character(),
        ###########################

        ###########################
        ### TEXT OPTIONS ##########
        # Whether to add texts to the plot
        addText           = 0,
        # List of texts to be added to plot
        texts             = character(),
        # X position of text in plot
        textsX            = numeric(),
        # Y position of text in plot
        textsY            = numeric(),
        # Size of the font
        textSize          = numeric(),
        # Angle of the text (0 is normal, 90 is vertical)
        textAngle         = numeric(),
        # Text colour
        textColour        = numeric(),
        ###########################

        
        #########################
        ### HISTOGRAM OPTIONS ###
        # These options are only valid if histogram = 1
        # normalScale is only valid is addNormal = 1
        # Add normal distribution
        histogramAddNormal     = 0,
        # If add normal distribution but scale is not
        # looking nice, adjust here
        histogramNormalScale   = 1,
        # Histogram bin properties
        histogramColour   = "blue",
        histogramFill     = "yellow",
        #########################
        
        #########################
        ### BAR CHART OPTIONS ###
        # Bar chart bin properties
        barColour         = "#000000",
        barFill           = "#999999",
        #########################

        ######################
        ### QQPLOT OPTIONS ###
        ## qqplot point properties
        qqplotPointColour = "red",
        qqplotPointFill   = "white", 
        qqplotPointShape  = 21, 
        qqplotPointSize   = 3,
        ## qqplot add regression line to chart
        qqplotRegressionLine = 1,
        ######################

        ###################
        ### ACF OPTIONS ###
        # The ACF is calculated based on the
        # data, but it may be provided if it is 
        # generated outside. For instance, R has
        # ACF functions for ARMA series.
        theoreticalACF = NULL,
        # Add or not confidence intervals
        acfConfidenceIntervals = 1,
        acfCILineColour        = "blue",
        acfCILineType          = "dashed"
        ###################


       
        

    );
    class(ggOptions) = "ggOptions";
    return (ggOptions);
}

getGGOptionsStandard <- function() {
    ggOptions <- getGGOptions();
    ggOptions$axisTitleSize = 16;
    ggOptions$axisLabelSize = 16;
    ggOptions$axisTitleBold = 0;
    ggOptions$removeXAxisSpace = 0;
    ggOptions$removeYAxisSpace = 0;
    ggOptions$height = 6;
    ggOptions$width = 8;
    return (ggOptions);
}

################################################
## AUXILIARY FUNCTIONS
printf <- function(...) invisible(cat(sprintf(...)))

checkPackage <- function(package) {
    if (!package %in% rownames(installed.packages())) {
        install.packages(package);
    }
}

loadPackage <- function(package) {
    checkPackage(package);
    suppressMessages(library(package, character.only = TRUE));
}

stop0 <- function(...) stop(..., call.=FALSE);
################################################

checkGGOptions <- function(ggOptions) {
    if (is.null(ggOptions))  stop0("ggOptions must be provided, cannot be null.");
    if (!is.list(ggOptions)) stop0("ggOptions is not a list.");
    if (class(ggOptions) != "ggOptions") stop0("The ggOptions parameter was not created properly.");
    
    if (ggOptions$lineChart   != 0) ggOptions$lineChart   = 1;
    if (ggOptions$scatterplot != 0) ggOptions$scatterplot = 1;
    if (ggOptions$polygon     != 0) ggOptions$polygon     = 1;
    if (ggOptions$barChart    != 0) ggOptions$barChart    = 1;
    if (ggOptions$histogram   != 0) ggOptions$histogram   = 1;
    if (ggOptions$density     != 0) ggOptions$density     = 1;
    if (ggOptions$qqplot      != 0) ggOptions$qqplot      = 1;
    if (ggOptions$acf         != 0) ggOptions$acf         = 1;

    if (ggOptions$histogram + ggOptions$lineChart + ggOptions$barChart + ggOptions$qqplot + ggOptions$acf + ggOptions$density + ggOptions$polygon > 1)
        stop0("You must choose a maximum of one between lineChart, barChart, histogram, qqplot, density, polygon and acf.");

    if (ggOptions$histogram + ggOptions$scatterplot + ggOptions$barChart + ggOptions$qqplot + ggOptions$acf + ggOptions$density > 1)
        stop0("You must choose a maximum of one between scatterplot, barChart, histogram, qqplot, density and acf.");

    if (ggOptions$stepFunction && !ggOptions$lineChart)
        stop0("Step function can only be used with line chart.");

    if (ggOptions$percentageInXAxis && ggOptions$formatXAxisAsDate)
        stop0("percentageInXAxis and formatXAxisAsDate cannot be 1 at the same time.");


    if (!is.null(ggOptions$xAxisLimits)) {
        if (!is.numeric(ggOptions$xAxisLimits)) stop0("xAxisLimits must be a numeric vector with two elements if not null.");
        if (length(ggOptions$xAxisLimits) != 2) stop0("xAxisLimits must be a numeric vector with two elements if not null.");
        if (ggOptions$xAxisLimits[1] >= ggOptions$xAxisLimits[2]) stop0("First element of xAxisLimits must be less than second element.");
    }
    
    if (!is.null(ggOptions$yAxisLimits)) {
        if (!is.numeric(ggOptions$yAxisLimits)) stop0("yAxisLimits must be a numeric vector with two elements if not null.");
        if (length(ggOptions$yAxisLimits) != 2) stop0("yAxisLimits must be a numeric vector with two elements if not null.");
        if (ggOptions$yAxisLimits[1] >= ggOptions$yAxisLimits[2]) stop0("First element of yAxisLimits must be less than second element.");
    }
    
    if (!is.null(ggOptions$yAxisBreaks)) {
        if (!is.numeric(ggOptions$yAxisBreaks)) stop0("yAxisBreaks mut be a numeric vector if not null.");
    }
    
    if (!is.null(ggOptions$xAxisBreaks)) {
        if (!is.numeric(ggOptions$xAxisBreaks)) stop0("xAxisBreaks mut be a numeric vector if not null.");
    }

    if (ggOptions$addSegments) {
        if (!is.numeric(ggOptions$segXBegin)) stop0("segXBegin must be numeric.");
        if (!is.numeric(ggOptions$segXEnd  )) stop0("segXend must be numeric."  );
        if (!is.numeric(ggOptions$segYBegin)) stop0("segYBegin must be numeric.");
        if (!is.numeric(ggOptions$segYEnd  )) stop0("segYEnd must be numeric."  );
        
        if (length(ggOptions$segXBegin) != length(ggOptions$segXEnd  )) stop0("Segments begins and ends must have the same length.");
        if (length(ggOptions$segXBegin) != length(ggOptions$segYBegin)) stop0("Segments begins and ends must have the same length.");
        if (length(ggOptions$segXBegin) != length(ggOptions$segYEnd  )) stop0("Segments begins and ends must have the same length.");
        if (length(ggOptions$segXBegin) == 0) stop0("You chose addSegments = 1 but no segments were added.");
    }

    if (ggOptions$addABLine) {
        if (!is.numeric(ggOptions$abSlope    )) stop0("abSlope must be numeric."    );
        if (!is.numeric(ggOptions$abIntercept)) stop0("abIntercept must be numeric.");
        if (!is.numeric(ggOptions$abSizes    )) stop0("abSizes must be numeric."    );
        if (!is.character(ggOptions$abColours)) stop0("abColours must be a character vector.");
        if (!is.character(ggOptions$abTypes  )) stop0("abTypes must be a character vector."  );
        
        if (length(ggOptions$abSlope) == 0 || length(ggOptions$abIntercept) == 0) stop0("You chose addABLine but no data for slopes and/or intercepts was provided.");
        if (length(ggOptions$abSlope) != length(ggOptions$abIntercept)) stop0("As addABLine was chosen, abSlope and abIntercept must have the same length.");
        if (length(ggOptions$abSizes  ) == 0 ) stop0("You chose addABLine but no abSizes were provided."  );
        if (length(ggOptions$abColours) == 0 ) stop0("You chose addABLine but no abColours were provided.");
        if (length(ggOptions$abTypes  ) == 0 ) stop0("You chose addABLine but no abTypes were provided."  );
    
    }

    if (ggOptions$addExtraPoints) {
        if (!is.numeric  (ggOptions$extraPointsX    )) stop0("extraPointsX must be numeric."    );
        if (!is.numeric  (ggOptions$extraPointsY    )) stop0("extraPointsY must be numeric."    );
        if (length(ggOptions$extraPointsX) != length(ggOptions$extraPointsY)) stop0("Extra points X and Y must have the same length.");
    }

    if (!inherits(ggOptions$shadedAreaPoints, "list")) stop0("ShadedAreaPoints must be a list");
    if (ggOptions$howManyShadedAreas > 0) {

        if (length(ggOptions$shadedAreaPoints) != ggOptions$howManyShadedAreas) stop0("The number of shaded areas must be equal to the number of data frames in shadedAreaPoints.");
        for (i in 1 : length(ggOptions$shadedAreaPoints)) {
            temp = ggOptions$shadedAreaPoints[[i]]
            if (!inherits(temp, "data.frame")) stop0(sprintf("shadedAreaPoints position %d is not a data frame.", i));
            if (ncol(temp) != 2)  stop0(sprintf("The data frame in shadedAreaPoints position %d must have two columns.", i));
            colnames(ggOptions$shadedAreaPoints[[i]]) = c("x", "y");
        }
    }

    if (ggOptions$addRectangles) {
        nr = length(ggOptions$rectanglesX1);
        if (nr <= 0) stop0("You set addRectangles = 1 but did not provide the x and y coordinates of any rectangle.");
        if (length(ggOptions$rectanglesX2) != nr) stop0("In rectangles, vectors rectanglesX1 and rectanglesX2 must have the same length.");
        if (length(ggOptions$rectanglesY1) != nr) stop0("In rectangles, vectors rectanglesX1 and rectanglesY1 must have the same length.");
        if (length(ggOptions$rectanglesY2) != nr) stop0("In rectangles, vectors rectanglesX1 and rectanglesY2 must have the same length.");
    }
}



applyOptions <- function(plot, xValues, ggOptions, numLines, cats = waiver()) {

    if (ggOptions$whiteBackground) plot = plot + theme_bw();
    
    if (ggOptions$title  != "") {
        #plot = plot + ggtitle(ggOptions$title);
        if (grepl("\\$", ggOptions$title)) {
            plot = plot + ggtitle(unname(TeX(ggOptions$title)));
        } else {
            plot = plot + ggtitle(ggOptions$title);
        }
        plot = plot + theme(plot.title = element_text(hjust = 0.5, size = ggOptions$titleSize, face = "bold"));
    }
   
    if (ggOptions$removeGridLines) {
        plot = plot + theme(panel.grid.minor =   element_blank(),
                            panel.grid.major =   element_blank());
    }
    
    col = colours1;
    if (length(ggOptions$customColours) >= numLines) {
        col = ggOptions$customColours;
    } else {
        if (ggOptions$colours == 2) col = colours2;
        if (ggOptions$colours == 3) col = colours3;
        if (ggOptions$colours == 4) col = colours4;
    }

    legendTitle = waiver();
    if (ggOptions$legendTitle != "") legendTitle = ggOptions$legendTitle;

    ## TODO This was originally in the end, if things don't work it may be necessary to move it.
    if (ggOptions$blackAndWhite == 1) {
        plot = plot + scale_color_grey();
    } else if (length(col) >= numLines) {
        plot = plot + scale_color_manual(values=col, name = legendTitle, breaks = cats);
    } else {
        plot = plot + scale_color_discrete(name = legendTitle, breaks = cats);
    }
    
    if (length(ggOptions$customLineTypes) >= numLines ) {
        if (ggOptions$useLineTypes == 0) printf("Warning in ggOptions: customLineTypes will have no effect unless you also set useLineTypes to 1.\n");
        plot = plot + scale_linetype_manual(values = ggOptions$customLineTypes, name = legendTitle, breaks = cats);
    } else {
        plot = plot + scale_linetype(name = legendTitle, breaks = cats);
    }

    if (length(ggOptions$customShapes) >= numLines ) {
        if (ggOptions$useShapes == 0) printf("Warning in ggOptions: customShapes will have no effect unless you also set useShapes to 1.\n");
        plot = plot + scale_shape_manual(values = ggOptions$customShapes, name = legendTitle, breaks = cats);
    } else {
        plot = plot + scale_shape(name = legendTitle, breaks = cats);
    }


    if (ggOptions$changeMargin) {
        if (is.numeric(ggOptions$margins) && length(ggOptions$margins) == 4) {
            plot = plot + theme(plot.margin=unit(ggOptions$margins,"cm"));
        } else {
            printf("Warning in ggOptions: margins were not enforced because they are not a vector of 4 numbers.");
        }
    }

    if (is.character(ggOptions$yTitle) && ggOptions$yTitle == "") {
        plot = plot + theme(axis.title.y=element_blank());
    } else {
        if (grepl("\\$", ggOptions$yTitle)) {
            plot = plot + ylab(unname(TeX(ggOptions$yTitle)));  
        } else {
            plot = plot + ylab(ggOptions$yTitle);  
        }
    }

    if (is.character(ggOptions$xTitle) && ggOptions$xTitle == "") {
        plot = plot + theme(axis.title.x=element_blank());
    } else {
        if (grepl("\\$", ggOptions$yTitle)) {
            plot = plot + xlab(unname(TeX(ggOptions$xTitle)));
        } else {
            plot = plot + xlab(ggOptions$xTitle);
        }
    }
    
    face = "plain";
    if (ggOptions$axisTitleBold == 1) face = "bold";
    if (ggOptions$axisXLabelSize == 0) ggOptions$axisXLabelSize = ggOptions$axisLabelSize;
    if (ggOptions$axisYLabelSize == 0) ggOptions$axisYLabelSize = ggOptions$axisLabelSize;
    plot = plot + theme(axis.text.x = element_text(size=ggOptions$axisXLabelSize, angle=ggOptions$axisXLabelAngle, vjust = ggOptions$axisXLabelVJust, hjust = 0.5), 
                        axis.text.y = element_text(size=ggOptions$axisYLabelSize, angle=ggOptions$axisYLabelAngle, vjust = 0.5, hjust = 0.5), 
                        axis.title  = element_text(size = ggOptions$axisTitleSize, face=face));

    if (ggOptions$addVerticalLine) {
        for (i in 1 : length(ggOptions$verticalLines)) {
            size   = ggOptions$verticalSizes[1];
            colour = ggOptions$verticalColours[1];
            type   = ggOptions$verticalTypes[1];

            if (length(ggOptions$verticalSizes  ) >= i) size   = ggOptions$verticalSizes  [i];
            if (length(ggOptions$verticalColours) >= i) colour = ggOptions$verticalColours[i];
            if (length(ggOptions$verticalTypes  ) >= i) type   = ggOptions$verticalTypes  [i];

            plot = plot + geom_vline(xintercept = ggOptions$verticalLines[i], size = size, color = colour, linetype = type);
        }
    }

    if (ggOptions$addHorizontalLine) {
        for (i in 1 : length(ggOptions$horizontalLines)) {
            size   = ggOptions$horizontalSizes[1];
            colour = ggOptions$horizontalColours[1];
            type   = ggOptions$horizontalTypes[1];

            if (length(ggOptions$horizontalSizes  ) >= i) size   = ggOptions$horizontalSizes  [i];
            if (length(ggOptions$horizontalColours) >= i) colour = ggOptions$horizontalColours[i];
            if (length(ggOptions$horizontalTypes  ) >= i) type   = ggOptions$horizontalTypes  [i];
            plot = plot + geom_hline(yintercept = ggOptions$horizontalLines[i], size = size, color = colour, linetype=type);
        }
    }

    if (ggOptions$addSegments) {
        for (i in 1 : length(ggOptions$segXBegin)) {
            coltemp = "blue";
            typetemp = "solid";
            lineTemp = ggOptions$lineSize;
            if (length(colours) >= i) coltemp = colours1[i]
            if (ggOptions$colours == 2 && length(colours2) >= i) coltemp = colours2[i];
            if (length(ggOptions$segColour) >= i) coltemp = ggOptions$segColour[i];
            if (length(ggOptions$segLineSize) >= i) lineTemp = ggOptions$segLineSize[i];
            if (length(ggOptions$segLineType) >= i) typetemp = ggOptions$segLineType[i];
            dftemp <- data.frame(x1 = ggOptions$segXBegin[i], x2 = ggOptions$segXEnd[i], y1 = ggOptions$segYBegin[i], y2 = ggOptions$segYEnd[i]);
            plot = plot + geom_segment(aes(x = x1, y = y1, xend = x2, yend = y2, colour = "segment"), colour = coltemp, size = lineTemp, data = dftemp, linetype = typetemp);
        }
    }


    if (ggOptions$addABLine) {
        for (i in 1 : length(ggOptions$abSlope)) {
            size   = ggOptions$abSizes[1];
            colour = ggOptions$abColours[1];
            type   = ggOptions$abTypes[1];

            if (length(ggOptions$abSizes  ) >= i) size   = ggOptions$abSizes  [i];
            if (length(ggOptions$abColours) >= i) colour = ggOptions$abColours[i];
            if (length(ggOptions$abTypes  ) >= i) type   = ggOptions$abTypes  [i];
            plot = plot + geom_abline(intercept = ggOptions$abIntercept[i], slope = ggOptions$abSlope[i], size = size, color = colour, linetype=type);
        }
    }

    if (ggOptions$addExtraPoints) {
        #dfpoints = data.frame(x = ggOptions$extraPointsX, y = ggOptions$extraPointsY);
        #plot = plot + geom_point(data = dfpoints, aes(x = x, y = y), colour = ggOptions$extraPointsColour, fill = ggOptions$extraPointsFill, shape = ggOptions$extraPointsShape, size = ggOptions$extraPointsSize);
        colourtemp = "blue";
        filltemp   = "blue";
        shapetemp  = 21; 
        sizetemp   = 3;
        for (i in 1 : length(ggOptions$extraPointsX)) {
            if (length(ggOptions$extraPointsColours) >= i) colourtemp = ggOptions$extraPointsColours[i];
            if (length(ggOptions$extraPointsFills  ) >= i) filltemp   = ggOptions$extraPointsFills  [i];
            if (length(ggOptions$extraPointsShapes ) >= i) shapetemp  = ggOptions$extraPointsShapes [i];
            if (length(ggOptions$extraPointsSizes  ) >= i) sizeemp    = ggOptions$extraPointsSizes  [i];
            plot = plot + geom_point(aes_string(x = ggOptions$extraPointsX[i], y = ggOptions$extraPointsY[i]), colour = colourtemp, fill = filltemp, shape = shapetemp, size = sizetemp);
        }

    }

    if (ggOptions$addRectangles) {
        if (ggOptions$formatXAxisAsDate && ggOptions$removeWeekends) printf("There is a known bug in ggplot: package bdscale to remove weekends does not work with geom_rect.\n");
        for (i in 1 : length(ggOptions$rectanglesX1)) {
            lineWidth  = 0.5;
            if (length(ggOptions$rectanglesLineWidth ) >= i) lineWidth  = ggOptions$rectanglesLineWidth [i];
            lineType   = "solid";
            if (length(ggOptions$rectanglesLineType  ) >= i) lineType   = ggOptions$rectanglesLineType  [i];
            lineColour = NA;
            if (length(ggOptions$rectanglesLineColour) >= i) lineColour = ggOptions$rectanglesLineColour[i];
            fillColour = "grey20";
            if (length(ggOptions$rectanglesFillColour) >= i) fillColour = ggOptions$rectanglesFillColour[i];
            opacity    = 0.05;
            if (length(ggOptions$rectanglesOpacity   ) >= i) opacity    = ggOptions$rectanglesOpacity   [i];
            inTheBack = 1;
            if (length(ggOptions$rectanglesInTheBack ) >= i) inTheBack  = ggOptions$rectanglesInTheBack [i];
            
            xmin = ggOptions$rectanglesX1[i];
            xmax = ggOptions$rectanglesX2[i];
            if (xmax < xmin) {
                a = xmin;
                xmin = xmax;
                xmax = a;
            }
            ymin = ggOptions$rectanglesY1[i];
            ymax = ggOptions$rectanglesY2[i];
            if (ymax < ymin) {
                a = ymin;
                ymin = ymax;
                ymax = a;
            }
            rect = NULL;
            if (ggOptions$formatXAxisAsDate) {
                if (!class(xmin) == "Date") xmin = as.Date(strptime(xmin, ggOptions$dateFormat));
                if (!class(xmax) == "Date") xmax = as.Date(strptime(xmax, ggOptions$dateFormat));
                rect = geom_rect(xmin = xmin, xmax = xmax, ymin = ymin, ymax = ymax,
                                 size = lineWidth, linetype = lineType, color = lineColour, fill = fillColour, alpha = opacity);
            } else {
                rect = geom_rect(xmin = xmin, xmax = xmax, ymin = ymin, ymax = ymax, size = lineWidth, linetype = lineType, color = lineColour, fill = fillColour, alpha = opacity);
            }
            if (inTheBack) {
                plot$layers = c(rect, plot$layers);
            } else {
                plot = plot + rect;
            }
        }
    }





    if (length(ggOptions$shadeAreaBegin) > 0) {
        numShades = length(ggOptions$shadeAreaBegin);
        if (length(ggOptions$shadeAreaColour) == 0 || length(ggOptions$shadeAreaOpacity) == 0) stop0("If you specify a shaded area, you must specify at least one colour and opacity level between 0 and 1.");
        if (length(ggOptions$shadeAreaEnd) != numShades) stop0("Length of shadeAreaBegin is different from length of shadeAreaEnd.");

        for (i in 1 : numShades) {
            shadeBeg <<- ggOptions$shadeAreaBegin[i]; 
            shadeEnd <<- ggOptions$shadeAreaEnd  [i]; 
            if (shadeBeg >= shadeEnd) stop0("Value in shadeAreaBegin must be less than corresponding value in shadeAreaEnd.");
            shadeColour  = ggOptions$shadeAreaColour[1];
            shadeOpacity = ggOptions$shadeAreaOpacity[1];
            if (length(ggOptions$shadeAreaColour ) >= i) shadeColour  = ggOptions$shadeAreaColour [i];
            if (length(ggOptions$shadeAreaOpacity) >= i) shadeOpacity = ggOptions$shadeAreaOpacity[i];
            
            plot = plot + layer(geom = "area", mapping = aes(x = ifelse(x > shadeBeg & x < shadeEnd, x, shadeEnd), colour=NA, linetype=NA),
                                position = "identity", stat="identity", params = list(fill = shadeColour, alpha = shadeOpacity),);
                               
        }
    } else {
        if (length(ggOptions$shadeAreaEnd) > 0) stop0("You specified shadeAreaEnd but not shadeAreaBegin.");
    }

    
    if (ggOptions$addLegend   == 0 ) {
        plot = plot + theme(legend.position="none");
    } else {
        plot = plot + theme(legend.position=ggOptions$legendPosition, legend.text=element_text(size=ggOptions$legendTextSize));
        if (ggOptions$legendKeyWidth > 0) {
            plot = plot + theme(legend.key.width = unit(ggOptions$legendKeyWidth, "cm"))
        }
    }
    if (ggOptions$legendTitle == "") {
        plot = plot + theme(legend.title=element_blank());
    } else {
        plot = plot + scale_fill_discrete(name = ggOptions$legendTitle);
    }
    if (ggOptions$legendSize > 0   ) plot = plot + theme(legend.text=element_text(size=ggOptions$legendSize));
  
    if (ggOptions$addText) {
        if (length(ggOptions$texts     ) == 0) stop0("You specified addText = 1 but the texts vector is empty.");
        if (length(ggOptions$textsX    ) == 0) ggOptions$textsX     = c(0);
        if (length(ggOptions$textsY    ) == 0) ggOptions$textsY     = c(0);
        if (length(ggOptions$textSize  ) == 0) ggOptions$textSize   = c(6);
        if (length(ggOptions$textAngle ) == 0) ggOptions$textAngle  = c(0);
        if (length(ggOptions$textColour) == 0) ggOptions$textColour = c("black");
        for (i in 1 : length(ggOptions$texts)) {
            textX      = ggOptions$textsX   [1];
            textY      = ggOptions$textsY   [1];
            textSize   = ggOptions$textSize [1];
            textAngle  = ggOptions$textAngle[1];
            textColour = ggOptions$textColour[1];
            
            if (i > 1 && length(ggOptions$textsX)     >= i) textX      = ggOptions$textsX    [i];
            if (i > 1 && length(ggOptions$textsY)     >= i) textY      = ggOptions$textsY    [i];
            if (i > 1 && length(ggOptions$textSize  ) >= i) textSize   = ggOptions$textSize  [i];
            if (i > 1 && length(ggOptions$textAngle ) >= i) textAngle  = ggOptions$textAngle [i];
            if (i > 1 && length(ggOptions$textColour) >= i) textColour = ggOptions$textColour[i];
            
            if (grepl("\\$", ggOptions$texts[i])) {
                plot = plot + annotate("text", x = textX, y = textY, label = unname(TeX(ggOptions$texts[i])), size = textSize, angle = textAngle, colour = textColour);
            } else {
                plot = plot + annotate("text", x = textX, y = textY, label = ggOptions$texts[i], size = textSize, angle = textAngle, colour = textColour);
            }
        }
    }


    if (ggOptions$howManyShadedAreas > 0) {
        for (i in 1 : length(ggOptions$shadedAreaPoints)) {
            col   = "gray";
            alpha = "0.4";
            if (length(ggOptions$shadedAreaColour ) >= i) col   = ggOptions$shadedAreaColour[i];
            if (length(ggOptions$shadedAreaOpacity) >= i) alpha = ggOptions$shadedAreaOpacity[i];
            plot = plot + geom_polygon(ggOptions$shadedAreaPoints[[i]], mapping = aes(x = x, y = y), color=ggOptions$polygonLineColour, 
                                   fill = col, alpha = alpha, size = 0);
        }
    }



    labels = ggOptions$xAxisBreaks;
    breaks = waiver();
    expand = waiver();
    limits = NULL;
    if (ggOptions$removeXAxisSpace) expand = c(0, 0);
    if (ggOptions$percentageInXAxis) {
        labels = scales::percent;
    } else {
        if (!is.null(labels)) {
            breaks = labels;
        } else {
            labels = waiver();
        }
    }
    if (!is.null(ggOptions$xAxisLimits)) limits = ggOptions$xAxisLimits;
    
    # TODO FIX this
    if (ggOptions$formatXAxisAsDate) {
        if (ggOptions$removeWeekends) {
            loadPackage("bdscale");
            plot = plot + scale_x_bd(business.dates = xValues, expand = expand);
        } else {
            plot = plot + scale_x_date(expand = expand);
            #plot = plot + scale_x_datetime(expand = expand);
        }
    } else {
        if (ggOptions$barChart) {
            plot = plot + scale_x_discrete(expand = expand, labels = labels, breaks = breaks);
        } else {
            trans = "identity";
            if (ggOptions$reverseXAxis) trans = "reverse"
            plot = plot + scale_x_continuous(limits = limits, expand = expand, labels = labels, breaks = breaks, trans = trans);
        }
    }

    labels = ggOptions$yAxisBreaks;
    breaks = waiver();
    expand = waiver();
    limits = NULL;
    if (ggOptions$removeYAxisSpace) expand = c(0, 0);
    if (ggOptions$percentageInYAxis) {
        labels = scales::percent;
    } else {
        if (!is.null(labels)) {
            breaks = labels;
        } else {
            labels = waiver();
        }
    }
    if (!is.null(ggOptions$yAxisLimits)) limits = ggOptions$yAxisLimits;
    plot = plot + scale_y_continuous(limits = limits, expand = expand, labels = labels, breaks = breaks);

    return (plot);   
}

printPlot <- function(plot, ggOptions) {
    print(plot);
    if (ggOptions$saveGraphics > 0) {
        if (!endsWith(ggOptions$imageName, ".png") && !endsWith(ggOptions$imageName, ".pdf")) stop0("Image filename must have extension .png or .pdf");
        ggsave(paste0(ggOptions$imageName), dpi=ggOptions$dpi, units="in", width=ggOptions$width, height=ggOptions$height);
        dev.off();
    }
}

###########################################################
# Specifics

prepareQQPlotRegressionLine <- function(ggOptions, df) {

    y <- quantile(df$x[!is.na(df$x)], c(0.25, 0.75));
    x <- qnorm(c(0.25, 0.75));
    slope <- diff(y)/diff(x);
    inter <- y[1L] - slope * x[1L];
    
    if (ggOptions$addABLine) {
        ggOptions$abSlope     = c(slope,   ggOptions$abSlope    );
        ggOptions$abIntercept = c(inter,   ggOptions$abIntercept);
        ggOptions$abSizes     = c(0.2,     ggOptions$abSizes    );
        ggOptions$abColours   = c("black", ggOptions$abColours  );
        ggOptions$abTypes     = c("solid", ggOptions$abTypes    );
    } else {
        ggOptions$abSlope     = c(slope);
        ggOptions$abIntercept = c(inter);
        ggOptions$abSizes     = c(0.2);
        ggOptions$abColours   = c("black");
        ggOptions$abTypes     = c("solid");
        ggOptions$addABLine   = 1;
    } 

    return (ggOptions);
}

prepareACFData <- function(ggOptions, df) {
    bacf <- acf(df[,1], plot = FALSE);
    bacfdf <- with(bacf, data.frame(lag, acf));
    if (!is.null(ggOptions$theoreticalACF)) {
        if (length(ggOptions$theoreticalACF) < nrow(bacfdf)) {
            ggOptions$theoreticalACF = c(ggOptions$theoreticalACF, rep(0, nrow(bacfdf) - length(ggOptions$theoreticalACF)));
        }
        bacfdf$acf = ggOptions$theoreticalACF;
    }
    return (bacfdf);
}

addACFProperties <- function(ggOptions, numberObservations) {
    if (ggOptions$addHorizontalLine) {
        ggOptions$horizontalLines   = c(0, ggOptions$horizontalLines);
        ggOptions$horizontalSizes   = c(0.5, ggOptions$horizontalSizes);
        ggOptions$horizontalColours = c("black", ggOptions$horizontalColours);
        ggOptions$horizontalTypes   = c("solid", ggOptions$horizontalTypes);
    } else {
        ggOptions$horizontalLines   = c(0);
        ggOptions$horizontalSizes   = c(0.5);
        ggOptions$horizontalColours = c("black", ggOptions$acfCILineColour);
        ggOptions$horizontalTypes   = c("solid", ggOptions$acfCILineType  );
        ggOptions$addHorizontalLine = 1;
    }
    
    if (ggOptions$acfConfidenceIntervals) {
        yi = 1.96/sqrt(numberObservations); 
        ggOptions$horizontalLines   = c(yi, -yi, ggOptions$horizontalLines);
        ggOptions$horizontalSizes   = c(0.5, 0.5, ggOptions$horizontalSizes);
        ggOptions$horizontalColours = c(ggOptions$acfCILineColour, ggOptions$acfCILineColour, ggOptions$horizontalColours);
        ggOptions$horizontalTypes   = c(ggOptions$acfCILineType,   ggOptions$acfCILineType, ggOptions$horizontalTypes);
    }
    return (ggOptions);
}

############################################################
# Data preparation

# TODO allow non-numeric series in case of barchart.

# Commented because using function is utils.r
#decimalPlaces <- function(x) {
#    if ((x %% 1) != 0) {
#        nchar(strsplit(sub('0+$', '', as.character(x)), ".", fixed=TRUE)[[1]][[2]]);
#    } else {
#        return(0);
#    }
#}



prepareNumericData <- function(data, ggOptions, xValues = NULL, categories = NULL) {
    
    if (length(data) == 0) stop0("No data to plot");
    size = 0;

    allHaveTheSameLength = 1;
    for (i in 1 : length(data)) {
        if (!is.numeric(data[[i]])) stop0("At least one series is not numeric");
        if (i == 1) size = length(data[[i]]);
        if (!is.null(xValues) && length(data[[i]]) != size) stop0("Data has inconsistent lengths");
        if ( is.null(xValues) && length(data[[i]]) != size) allHaveTheSameLength = 0;
    }

    if (ggOptions$histogram || ggOptions$qqplot || ggOptions$acf) {
        if (!is.null(xValues)) printf("Warning: xValues passed as parameter is ignored if chart is barChart, histogram, qqplot or acf.\n"); 
        return (data.frame(x = data[[1]]));
    }
    
    if (ggOptions$density) {
        if (!is.null(xValues)) printf("Warning: xValues passed as parameter is ignored if chart is density.\n"); 
    }

    if (!is.null(categories)) {
        if (length(data[[i]]) != length(categories)) stop0("Categories must have the same length as the data.");
        if (length(data) != 1) stop0("As categories were provided and data is numeric vector, data must be a single vector.");
    }


    if (is.null(xValues)) xValues = seq(1, size);
    if (!ggOptions$barChart && !is.numeric(xValues)) stop0("xValues, or x label values, must be numeric.");
    if (length(xValues) != size) stop0("xValues length is inconsistent with data.");
    if (ggOptions$barChart) xValues = as.character(xValues);

    plotData <- data.frame(x = xValues);

    if (ggOptions$formatXAxisAsDate) {
        plotData <- data.frame(x = as.Date(strptime(xValues, ggOptions$dateFormat)));
        #plotData <- data.frame(x = as.POSIXct(strptime(xValues, ggOptions$dateFormat)));
        #if (ggOptions$removeWeekends) {
        #    plotData <- data.frame(x = factor(as.POSIXct(strptime(xValues, ggOptions$dateFormat))));
        #} else {
        #    plotData <- data.frame(x = as.POSIXct(strptime(xValues, ggOptions$dateFormat)));
        #}
    }
    
    if (!is.null(categories)) {
        if (ggOptions$normalise == 1) printf("Warning: normalise is ignored if categories is not null.");
        plotData$value = data[[1]];
        plotData$variable = categories;
    } else if (!allHaveTheSameLength) {
        numTotal = 0;
        for (i in 1 : length(data)) {
            numTotal = numTotal + length(data[[i]]);    
        }
        plotData = data.frame(x = numeric(numTotal), variable = character(numTotal), value = numeric(numTotal), stringsAsFactors = 0);
        current = 1;
        for (i in 1 : length(data)) {
            s = length(data[[i]]);
            plotData$x       [current:(current+s-1)] = seq(1, s);
            plotData$variable[current:(current+s-1)] = rep(ggOptions$legend[i], s);
            plotData$value   [current:(current+s-1)] = data[[i]];
            current = current + s;
        }
    } else {
        for (i in 1 : length(data)) {
            denominator = 1;
            if (ggOptions$normalise == 1) denominator = data[[i]][1];
            plotData[[i+1]] <- data[[i]] / denominator;
            if (length(ggOptions$legend) >= i) {
                names(plotData)[i+1] = ggOptions$legend[i];
            }
        }
        plotData <- melt(plotData, id=names(plotData)[1]);
    }
    
    if (ggOptions$barChart) plotData$x = factor(plotData$x, levels = plotData$x);
    return(plotData);
}

prepareDataFrame <- function(data, ggOptions, categories = NULL) {
    
    if (length(data) == 0) stop0("No data to plot");
    if (length(data) != 1 || !is.data.frame(data[[1]])) stop0("Data provided was not a single data frame");

    data = data[[1]];
    if (!is.null(categories)) {
        if (nrow(data) != length(categories)) stop0("Categories must have the same length as the data.");
        if (ncol(data) != 2) stop0("As categories were provided, data must have only two columns, X and Y values.");
    }
    
    if (ggOptions$histogram || ggOptions$qqplot || ggOptions$acf || ggOptions$barChart) {
        if (ncol(data) == 1) return (data);
        return (data.frame(x = data[,2]));
    }

    if (ncol(data) < 2) stop0("Data frame provided must have at least two columns, the first being the x values.");

    if (ggOptions$formatXAxisAsDate) {
        data[,1] = as.Date(strptime(data[,1], ggOptions$dateFormat));
        #data[,1] = as.POSIXct(strptime(data[,1], ggOptions$dateFormat));
        #if (ggOptions$removeWeekends) {
        #    data[,1] = factor(as.POSIXct(strptime(data[,1], ggOptions$dateFormat)));
        #} else {
        #    data[,1] = as.POSIXct(strptime(data[,1], ggOptions$dateFormat));
        #}
    }
    
    plotData = data;
    if (!is.null(categories)) {
        if (ggOptions$normalise == 1) printf("Warning: normalise is ignored if categories is not null.");
        plotData$variable = categories;
        names(plotData)[1] = "x";
        names(plotData)[2] = "value";
    } else {
        plotData <- data.frame(x = data[,1]);
        for (i in 2 : length(data)) {
            denominator = 1;
            if (ggOptions$normalise == 1) denominator = data[[i]][1];
            plotData[[i]] <- data[[i]] / denominator;
            if (length(ggOptions$legend) >= (i-1)) {
                names(plotData)[i] = ggOptions$legend[i-1];
            }
        }
        plotData <- melt(plotData, id=names(plotData)[1]);
    }

    return(plotData);
}

checkProbabilities <- function(probabilities, dataDimension) {

    if (!ggOptions$stepFunction) {
        if (!is.null(probabilities))
            stop0("Probabilities can only be assigned if stepFunction = 1.");
    } else {
        if (is.null(probabilities)) 
            stop0("Probabilities cannot be null if you choose stepFunction.");
    }
    if (!is.numeric(probabilities)) stop0("Probabilities must be a numeric vector.");
    if (length(probabilities) != dataDimension) stop0("Vector of probabilities must have the same length as data.");
    if (sum(probabilities < 0) > 0) stop0("There are negative probabilities.");
    if (sum(probabilities) != 1) {
        printf("Warning: probabilities provided do not sum to 1, so they were normalised.\n");
        probabilities = probabilities / sum(probabilities);
        probabilities = round(probabilities, 5);
    }
    return (probabilities);
}

checkCategories <- function(categories, ggOptions) {
    if (!ggOptions$lineChart && !ggOptions$scatterplot) {
        if (!is.null(categories))
            stop0("Categories can only be assigned with line chart and scatterplot.");
    }
    if (ggOptions$stepFunction) {    
        if (!is.null(categories))
            stop0("Categories cannot be assigned with step function, only pure line chart and/or scatterplot.");
    }
}

prepareStepFunction <- function(data, ggOptions, probabilities = NULL) {
        
    if (!ggOptions$stepFunction) return(data);
    if (length(data) > 1) stop0("Currently step function works only with single numeric vector.");
    if (!is.numeric(data[[1]])) stop0("Currently step function works only with single numeric vector.");
    
    data = data[[1]];
    probabilities = checkProbabilities(probabilities, length(data));
    df1 = matrix(rep(0, 4 + length(data)*4), ncol = 2); 

    dif = data[length(data)] - data[1];
    offset = dif / 14;
    sumProb = 0;
    df1[1,1] = data[1] - offset;
    df1[1,2] = 0;
    df1[nrow(df1),1] = data[length(data)] + offset;
    df1[nrow(df1),2] = 1;
    for (i in 1 : length(data)) {
        df1[2*(i-1)+2,1] = data[i];
        df1[2*(i-1)+2,2] = sumProb;
        sumProb = sumProb + probabilities[i];
        df1[2*(i-1)+3,1] = data[i];
        df1[2*(i-1)+3,2] = sumProb;

    }
    df1 = data.frame(x = df1[,1], y = df1[,2]);
    return(list(df1));
}

prepareDataWithProbabilities <- function(data, ggOptions, probabilities = NULL) {
    if (is.null(probabilities)) return (data);
    
    if (ggOptions$stepFunction) return(data);

    probabilities = checkProbabilities(probabilities, nrow(data));
    maxDecimal = 1;
    for (i in 1 : length(probabilities)) {
        if (decimalPlaces(probabilities[i]) > maxDecimal) {
            maxDecimal = decimalPlaces(probabilities[i]);
        }
    }
    term = 10^maxDecimal;
    df = numeric(0);
    for (i in 1 : length(probabilities)) {
        df = c(df, rep(data[i,1], floor(term*probabilities[i])));
    }
    return (data.frame(x = df));
}


defineAesthetics <- function(ggOptions) {
   
    myAes = aes(x = x, y = value, colour = variable);
    #if (ggOptions$barChart) {
    #    myAes = aes(x = factor(x));
    if (ggOptions$barChart) {
        myAes = aes(x = x, y = value);
    } else if (ggOptions$histogram) {
        myAes = aes(x = x);
    } else if (ggOptions$density) {
        if (ggOptions$useLineTypes) {
            myAes = aes(x = value, y = ..count../sum(..count..), group = variable, colour = variable, linetype = variable);
        } else {
            myAes = aes(x = value, y = ..count../sum(..count..), group = variable, colour = variable);
        }
    } else if (ggOptions$qqplot) {
        myAes = aes(sample = x);
    } else if (ggOptions$acf) {
        myAes = aes(x = lag, y = acf);
    } else {
        if (ggOptions$useLineTypes && !ggOptions$useShapes) {
            myAes = aes(x = x, y = value, colour = variable, linetype = variable);
        } else if (!ggOptions$useLineTypes && ggOptions$useShapes) {
            myAes = aes(x = x, y = value, colour = variable, shape = variable);
        } else if (ggOptions$useLineTypes && ggOptions$useShapes) {
            myAes = aes(x = x, y = value, colour = variable, linetype = variable, shape = variable);
        }
    }

    # myAes = aes(x = x, y = value, colour = variable, linetype = variable, group = variable);
    return (myAes)
}


# Accepts single data frame or list of numeric vectors
plotGraph <- function(..., ggOptions = NULL, xValues = NULL, probabilities = NULL, categories = NULL, returnPlot = 0) {
    
    loadPackage("ggplot2");
    loadPackage("reshape2");
    loadPackage("latex2exp");


    checkGGOptions(ggOptions);

    data = list(...);
    if (length(data) == 1 && inherits(data[[1]], "list")) data = data[[1]];
    if (ggOptions$stepFunction) data = prepareStepFunction(data, ggOptions, probabilities);
    checkCategories(categories, ggOptions);
    
    df = NULL;
    if (length(data) == 1 && is.data.frame(data[[1]])) {
        if (!is.null(xValues)) stop0("xValues must only be used if numeric vectors are provided as data (instead of data frame).");
        df = prepareDataFrame(data, ggOptions = ggOptions, categories = categories);
    } else {
        df = prepareNumericData(data, ggOptions = ggOptions, xValues = xValues, categories = categories);
    }
    
    df = prepareDataWithProbabilities(df, ggOptions, probabilities);
    numberObservations = nrow(df);
    
    if (ggOptions$acf) df = prepareACFData(ggOptions, df); 
    
    myAes = defineAesthetics(ggOptions);


    #if (ggOptions$formatXAxisAsDate && ggOptions$removeWeekends && (ggOptions$lineChart || ggOptions$addPath)) {
    #    ggOptions$singlePath = 1;
    #}

    plot  = ggplot(data = df, mapping = myAes); 
    
    if (ggOptions$scatterplot && !ggOptions$lineBelowPoints) plot = plot + geom_point(lwd = ggOptions$pointSize);

    if (ggOptions$polygon) {
        plot = plot + geom_polygon(df, mapping = aes(x = x, y = value, fill = variable, group = variable), color=ggOptions$polygonLineColour, 
                                   fill = ggOptions$polygonFillColour, linetype = ggOptions$polygonLineType, alpha = ggOptions$polygonAlpha, size = ggOptions$polygonLineWidth);
    }

    if (ggOptions$density) {
        plot = plot + geom_density(size = ggOptions$lineSize);
        #plot = plot + geom_line(stat="density", size = ggOptions$lineSize);
    }
 
    if (ggOptions$lineChart) {
        if (ggOptions$lineInheritAesthetics) {
            if (ggOptions$singlePath) {
                plot = plot + geom_line(size = ggOptions$lineSize, mapping = aes(x = x, y = value, group = 1));
            } else {
                plot = plot + geom_line(size = ggOptions$lineSize);
            }
        } else {
            if (ggOptions$singlePath) {
                plot = plot + geom_line(size = ggOptions$lineSize, mapping = aes(x = x, y = value), inherit.aes = FALSE);
            } else {
                plot = plot + geom_line(size = ggOptions$lineSize, mapping = aes(x = x, y = value, group = variable), inherit.aes = FALSE);
            }
        }
    }
    
    if (ggOptions$addPath) {
        if (ggOptions$pathInheritAesthetics) {
            if (ggOptions$singlePath) {
                plot = plot + geom_path(size = ggOptions$lineSize, mapping = aes(x = x, y = value));
            } else {
                plot = plot + geom_path(size = ggOptions$lineSize);
            }
        } else {
            if (ggOptions$singlePath) {
                plot = plot + geom_path(size = ggOptions$lineSize, mapping = aes(x = x, y = value), inherit.aes = FALSE);
            } else {
                plot = plot + geom_path(size = ggOptions$lineSize, mapping = aes(x = x, y = value, group = variable), inherit.aes = FALSE);
            }
        }
    }
    
    if (ggOptions$scatterplot && ggOptions$lineBelowPoints) plot = plot + geom_point(lwd = ggOptions$pointSize);
    
    #if (ggOptions$barChart) {
    #    plot = plot + geom_bar(aes(y = (..count..)/sum(..count..)), color= ggOptions$barColour, fill = ggOptions$barFill);
    #}
    
    if (ggOptions$barChart) {
	    plot = plot + geom_bar(stat = "identity", color= ggOptions$barColour, fill = ggOptions$barFill);
    }

    if (ggOptions$qqplot) {
        if (ggOptions$qqplotRegressionLine) ggOptions = prepareQQPlotRegressionLine(ggOptions, df);
        plot = plot + geom_point(stat  = "qq", colour = ggOptions$qqplotPointColour, fill = ggOptions$qqplotPointFill, 
                                 shape = ggOptions$qqplotPointShape, size = ggOptions$qqplotPointSize);
    }
    
    if (ggOptions$acf) {
        ggOptions = addACFProperties(ggOptions, numberObservations);
        plot = plot + geom_segment(mapping = aes(xend = lag, yend = 0));
    }

    if (ggOptions$histogram) {
        plot = plot + geom_histogram(aes(y = ..density..), binwidth=density(df$x)$bw, colour = ggOptions$histogramColour, fill = ggOptions$histogramFill);
        #plot = plot + geom_histogram(aes(y = ..density..), bins = 50, colour = "blue", fill = "yellow");
        #plot = plot + geom_histogram(aes(y = (..count..)/sum(..count..)), bins = 50, colour = "blue", fill = "yellow");
        if (ggOptions$histogramAddNormal) {
            plot = plot + stat_function(
               fun = function(x, mean, sd, n){
                    n * dnorm(x = x, mean = mean, sd = sd);
                }, 
                args = with(df, c(mean = mean(x), sd = sd(x), n = ggOptions$histogramNormalScale))
            );
        }
    }
   
    numLines = 1;
    cats     = waiver();
    if ("variable" %in% colnames(df)) {
        numLines = length(unique(df$variable));
        cats = unique(df$variable);
    }
    plot = applyOptions(plot, xValues = df[,1], ggOptions = ggOptions, numLines = numLines, cats = cats);

    if (returnPlot) {
        return(plot);
    } else {
        printPlot(plot, ggOptions);
    }
}


# TODO consistency check on layout matrix
plotMultipleGraphs <- function(..., dpi = 300, imageName = "temp", save = 0,
                               width = 12.0, height = 7.06, adjustment = c(0), layout = NULL) {

    # Other layout matrices:
    # https://cran.r-project.org/web/packages/gridExtra/vignettes/arrangeGrob.html

    loadPackage("grid");
    loadPackage("gridExtra");
    plots = list(...);
    
    for (i in 1 : length(plots)) {
        adj = 0;
        if (is.numeric(adjustment)) {
            if (i <= length(adjustment)) {
                adj = adjustment[i];
            } else {
                adj = adjustment[1];
            }
        }
        plots[[i]] = plots[[i]] + theme(axis.title.y=element_text(margin=margin(0, adj, 0, 0))); 
    }
    #multiPlot = arrangeGrob(grobs = plots, layout_matrix = rbind(c(1), c(2)));
    
    if (is.null(layout)) layout = matrix(seq(1, length(plots)), ncol = 1);
    multiPlot = arrangeGrob(grobs = plots, layout_matrix = layout);
    grid.draw(multiPlot);
    if (save == 1) {
        if (!endsWith(imageName, ".png") && !endsWith(imageName, ".pdf")) stop0("Image filename must have extension .png or .pdf");
        ggsave(multiPlot, file = imageName, dpi = dpi, units = "in", width = width, height = height);
        dev.off();
    }
}


plotBarPlot2 <- function(categories, probabilities, ggOptions, percent = FALSE) {
 
    portfolio <- data.frame(name = categories, w = round(probabilities, 3));
    plot = ggplot(portfolio, aes(x = name, y = w), fill = dose);
	plot = plot + geom_bar(stat = "identity", color= "black", fill = "blue");
    plot = plot + scale_y_continuous(labels = scales::percent)
    #plot = applyOptionsDiscrete(plot, ggOptions, numLines = 1);
    printPlot(plot, ggOptions);
}


