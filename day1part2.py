#output of 6483 was too high
currentPosition=50
password=0
def turn(amount, direction):
    global password
    global currentPosition
    
    if direction=='R':
        while(amount>0):
            amount-=1
            if(currentPosition==99):
                currentPosition=0
                password+=1
                # print("pw")
            else:
                currentPosition+=1
    else:
        while(amount>0):
            amount-=1
            if(currentPosition==0):
                currentPosition=99
                password+=1
                # print("pw")

            else:
                currentPosition-=1

    # print(currentPosition)
    return currentPosition

with open('day1input.txt', 'r') as file:
    for line in file:
        oldpw=password
        line=line.strip()
        value=int(line[1:])
        turn(value,line[0])
        print(line, currentPosition, password-oldpw)

print(password)