# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    "*** YOUR CODE HERE ***"
    start = problem.getStartState()
    actions = []
    stack = util.Stack()
    stack.push(problem.getSuccessors(start))
    expanded = set()
    expanded.add(start)
    while(not stack.isEmpty()):
        children = stack.pop()
        if(len(children) == 0):
            actions.pop()
            continue
        curr = children[0]
        stack.push(children[1:])

        if(curr[0] in expanded):
            continue
        else:
            expanded.add(curr[0])
            actions.append(curr[1])
            if (problem.isGoalState(curr[0])):
                break
            else:
                stack.push(problem.getSuccessors(curr[0]))
                
    return actions

def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""
    "*** YOUR CODE HERE ***"
    start = problem.getStartState()
    queue = util.Queue()
    curr = (start, 0, (-1,-1))
    queue.push(curr) # 1- node coordinate, 2- move, 3- parent coordinate
    visited = {}
    while(not queue.isEmpty()):
        curr = queue.pop()

        if curr[0] in visited:
            continue
        else:
            visited[curr[0]] = (curr[1], curr[2])

        if(problem.isGoalState(curr[0])):
            break
        
        for node in problem.getSuccessors(curr[0]):
            queue.push((node[0], node[1], curr[0]))
    
    # reverting path
    actions = []
    last_checked = curr[0]
    while(last_checked != start):
        actions = [visited[last_checked][0]] + actions
        last_checked = visited[last_checked][1]
    return actions

def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    "*** YOUR CODE HERE ***"
    start = problem.getStartState()
    pqueue = util.PriorityQueue()
    # 0- node coordinate, 1- priority, 2- move, 3- parent coordinate, 4- parent priority
    curr = (start, 0, 0, (-1,-1), 0)
    pqueue.push(curr, 0) 
    visited = {}
    while(not pqueue.isEmpty()):
        curr = pqueue.pop()

        if curr[0] in visited:
            continue
        else:
            visited[curr[0]] = (curr[1], curr[2], curr[3], curr[4])

        if(problem.isGoalState(curr[0])):
            break
        
        for node in problem.getSuccessors(curr[0]):
            pqueue.push((node[0], node[2]+curr[1], node[1], curr[0], curr[1]),  node[2]+curr[1])
    
    actions = []
    last_checked = curr[0]
    while(last_checked != start):
        actions = [visited[last_checked][1]] + actions
        last_checked = visited[last_checked][2]
    return actions


def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def greedySearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest heuristic first."""
    "*** YOUR CODE HERE ***"
    start = problem.getStartState()
    pqueue = util.PriorityQueue()
    # 0- node coordinate, 1- priority, 2- move, 3- parent coordinate, 4- parent priority
    curr = (start, heuristic(start, problem), 0, (-1,-1), 0)
    pqueue.push(curr, heuristic(start, problem)) 
    visited = {}
    while(not pqueue.isEmpty()):
        curr = pqueue.pop()

        if curr[0] in visited:
            continue
        else:
            visited[curr[0]] = (curr[1], curr[2], curr[3], curr[4])

        if(problem.isGoalState(curr[0])):
            break
        
        for node in problem.getSuccessors(curr[0]):
            pqueue.push((node[0], heuristic(node[0], problem), node[1], curr[0], curr[1]),  heuristic(node[0], problem))
    
    actions = []
    last_checked = curr[0]
    while(last_checked != start):
        actions = [visited[last_checked][1]] + actions
        last_checked = visited[last_checked][2]
    return actions


def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    "*** YOUR CODE HERE ***"
    start = problem.getStartState()
    pqueue = util.PriorityQueue()
    # 0- node coordinate, 1- real-cost, 2- move, 3- parent coordinate, 4- parent priority
    curr = (start, 0, 0, (-1,-1), 0)
    pqueue.push(curr, heuristic(start, problem))
    visited = {}
    while(not pqueue.isEmpty()):
        curr = pqueue.pop()

        if curr[0] in visited:
            continue
        else:
            visited[curr[0]] = (curr[1], curr[2], curr[3], curr[4])

        if(problem.isGoalState(curr[0])):
            break
        
        for node in problem.getSuccessors(curr[0]):
            pqueue.push((node[0], node[2]+curr[1], node[1], curr[0], curr[1]),  heuristic(node[0], problem)+node[2]+curr[1])
    
    actions = []
    last_checked = curr[0]
    while(last_checked != start):
        actions = [visited[last_checked][1]] + actions
        last_checked = visited[last_checked][2]
    return actions

def foodHeuristic(state, problem):
    """
    Your heuristic for the FoodSearchProblem goes here.

    This heuristic must be consistent to ensure correctness.  First, try to come
    up with an admissible heuristic; almost all admissible heuristics will be
    consistent as well.

    If using A* ever finds a solution that is worse uniform cost search finds,
    your heuristic is *not* consistent, and probably not admissible!  On the
    other hand, inadmissible or inconsistent heuristics may find optimal
    solutions, so be careful.

    The state is a tuple ( pacmanPosition, foodGrid ) where foodGrid is a Grid
    (see game.py) of either True or False. You can call foodGrid.asList() to get
    a list of food coordinates instead.

    If you want access to info like walls, capsules, etc., you can query the
    problem.  For example, problem.walls gives you a Grid of where the walls
    are.

    If you want to *store* information to be reused in other calls to the
    heuristic, there is a dictionary called problem.heuristicInfo that you can
    use. For example, if you only want to count the walls once and store that
    value, try: problem.heuristicInfo['wallCount'] = problem.walls.count()
    Subsequent calls to this heuristic can access
    problem.heuristicInfo['wallCount']
    """
    position, foodGrid = state
    "*** YOUR CODE HERE ***"
    foodList = foodGrid.asList()
    totalCost = 0
    curPoint = position
    while foodList:
        cost, food = \
            min([(util.manhattanDistance(curPoint, food), food) for food in foodList])
        foodList.remove(food)
        curPoint = food
        totalCost += cost
    return totalCost

# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
ucs = uniformCostSearch
gs = greedySearch
astar = aStarSearch
