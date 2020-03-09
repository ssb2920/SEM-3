import random
import sys
import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt
      
playerScore=0 #global variable
cpuScore=0 #global variable
p1rock=0
p1paper=0
p1scissors=0
p2rock=0
p2paper=0
p2scissors=0
def play():
    global playerScore,cpuScore
    p_choice = input("What do you choose?").capitalize()
    choices = {1 : 'Rock', 2 : 'Paper', 3 : 'Scissors'}
    cpu_choice = choices[random.randint(1,3)]
    if p_choice == cpu_choice:
        playerScore += 1
        cpuScore += 1
        return print('Tie!')
    if compare(p_choice,cpu_choice):
        playerScore += 1
        return print('You Win!')
    else:
        cpuScore += 1
        return print('You Lose!')

def compare(playerChoice,cpuChoice):
    global p1paper,p1rock,p1scissors,p2paper,p2rock,p2scissors
    results = {('Paper','Rock') : True,
               ('Paper','Scissors') : False,
               ('Rock','Paper') : False,
               ('Rock','Scissors') : True,
               ('Scissors','Paper') : True,
               ('Scissors','Rock') : False}
    if playerChoice=='Rock':
        p1rock += 1
    elif playerChoice == 'Paper':
        p1paper += 1
    else:
        p1scissors += 1
    if cpuChoice=='Rock':
        p2rock += 1
    elif cpuChoice=='Paper':
        p2paper += 1
    else:
        p2scissors += 1
    return results[(playerChoice,cpuChoice)]

def score():
    global playerScore,cpuScore
    print("Player Score="+str(playerScore)+" CPU Score="+str(cpuScore))

def game_start():
    begin = input("Would you like to play Rock, Paper, Scissors? ").capitalize()
    while begin != "Yes":
        if begin == "No":
            print("Game Over")
            sys.exit()
        else:
            print("Please try again")
            begin = input("Would you like to play Rock, Paper, Scissors? ").capitalize()
    play()
    while True:
        begin = input('Play again?').capitalize()
        while begin != "Yes":
            if begin == "No":
                print("Game Over")
                score()
                plot_bar()
                sys.exit()
            else:
                print("Please try again")
                begin = input("Play again? ").capitalize()
        play()

def plot_bar():
    # data to plot
    n_groups = 3
    means_p1 = (p1rock, p1paper, p1scissors)
    means_cpu = (p2rock, p2paper, p2scissors)
 
    # create plot
    fig, ax = plt.subplots()
    index = np.arange(n_groups)
    bar_width = 0.35
    opacity = 0.8
 
    rects1 = plt.bar(index, means_p1, bar_width,
    alpha=opacity,
    color='b',
    label='Player1')
 
    rects2 = plt.bar(index + bar_width, means_cpu, bar_width,
    alpha=opacity,
    color='g',
    label='CPU')
 
    plt.xlabel('Person')
    plt.ylabel('Scores')
    plt.title('Scores by person')
    plt.xticks(index + bar_width, ('Rock', 'Paper', 'Scissors'))
    plt.legend()
 
    plt.tight_layout()
    plt.show()
	
game_start()            
