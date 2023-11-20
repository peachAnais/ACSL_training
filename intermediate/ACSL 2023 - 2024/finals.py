import pandas as pd

string = "(-1, 5]"  # Interval string

#this function takes a string respresentaion of an interval according to mathematical notation adn transform it into a pandas interval
def strToInterval(interval):
    start = interval[0]
    end = interval[len(interval) - 1]

    # Extract the bounds and inclusivity
    bracket_left, bracket_right = interval[0], interval[-1]
    start_str, end_str = interval[1:-1].split(',')

    if start == '(' and end == ')':
        closed = 'neither'
    elif start == '(' and end == ']':
        closed = 'right'
    elif start == '[' and end == ')':
        closed = 'left'
    else:
        closed = 'both'

    interval_begin = int(start_str)
    interval_end = int(end_str)

    return pd.Interval(interval_begin, interval_end, closed = closed)

def intervalList2Set(intervalList):
    # Extract numbers from the interval
    numbers = []
    ret = set()
    for interval in intervalList:
        if interval.closed_left:
            start = interval.left
        else:
            start = interval.left + 1

        if interval.closed_right:
            end = interval.right
        else:
            end = interval.right - 1

        numbers = list(range(start, end + 1))
        ret.update(numbers)

    return ret

def solveProblems(intervals1, intervals2, intervals3):
    #so far, we have created lists of pandas intervals
    interval_list1 = intervals1.split(' ')
    for i in range(len(interval_list1)):
        interval_list1[i] = strToInterval(interval_list1[i])
    
    interval_list2 = intervals2.split(' ')
    for i in range(len(interval_list2)):
        interval_list2[i] = strToInterval(interval_list2[i])

    set1 = intervalList2Set(interval_list1)
    set2 = intervalList2Set(interval_list2)

    if intervals3 == 'null':
        commons = set1.intersection(set2)
        fin = set1.union(set2).difference(commons)

        return sum(fin)

    # only gets here if interval set3 is not null
    # second case here with 3 full sets of intervals
    interval_list3 = intervals3.split(' ')
    for i in range(len(interval_list3)):
        interval_list3[i] = strToInterval(interval_list3[i])

    #end of creation of pandas intervals
    set3 = intervalList2Set(interval_list3) 

    commons = set1.intersection(set2).intersection(set3)
    
    only_set_1 = set1.difference(set2).difference(set3)
    only_set_2 = set2.difference(set1).difference(set3)
    only_set_3 = set3.difference(set1).difference(set2)
    resulting_set = only_set_1.union(only_set_2).union(only_set_3)
    s1 = sum(resulting_set)
    in_two_sets = (set1 & set2) | (set2 & set3) | (set3 & set1)
    in_two_sets_only = in_two_sets - commons
    s2 = sum(in_two_sets_only)

    print(s1, s2)
            

intervals1 = '(5,10] [24,25) [13,20] (0,4)'
intervals2 = '[1,5) [25,26] (8,12] (15,24)'
intervals3 = '[4,12] [-5,3) (12,25]'

# intervals1 = '(5,10) (-5,2] [24,28] [12,22)'
# intervals2 = '[1,4] [15,25) [-4,-1) (7,12]'
# intervals3 = 'null'

solveProblems(intervals1, intervals2, intervals3)
