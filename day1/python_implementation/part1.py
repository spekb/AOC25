currentPosition=50
password=0
def turn(currentPosition,amount):
    global password
    currentPosition=(currentPosition+amount)%100
    if currentPosition==0:
        password+=1
    # print(currentPosition)
    return currentPosition

# vals=[-68,-30,48,-5,60,-55,-1,-99,14,-82]
# for i in vals:
#     currentPosition=turn(currentPosition,i)
    
with open('day1input.txt', 'r') as file:
    for line in file:
        oldpw=password
        line=line.strip()
        value=-1*int(line[1:]) if line[0]=='L' else int(line[1:])
        currentPosition=turn(currentPosition,value)
        print(line, currentPosition, password-oldpw)

print(password)