testcases = int(input())

for j in range(testcases):
    goal = {}
    score = {}
    for i in range(12):
        s = input().split()
        t1_name = s[0]
        t1_score = int(s[1])
        t2_name= s[4]
        t2_score = int(s[3])

        if not t1_name in goal.keys():
            goal[t1_name] = 0
            score[t1_name] = 0


        if not t2_name in goal.keys():
            goal[t2_name] = 0
            score[t2_name] = 0
    
        if t1_score > t2_score :
            score[t1_name] += 3
            goal[t1_name] += t1_score - t2_score
            goal[t2_name] += t2_score - t1_score

        elif t2_score > t1_score :
            score[t2_name] += 3
            goal[t1_name] += t1_score - t2_score
            goal[t2_name] += t2_score - t1_score
        else :
            score[t2_name] += 1
            score[t1_name] += 1
    
    d = sorted(score ,key = lambda k :  (score[k],goal[k]) ,reverse = True)
    print(d[0],d[1])

        
        