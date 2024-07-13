#dictionary
# dis ={
#     'A':'clean',
#     'B':'dirty'        
#     }
# print(dis)

# Vaccum clean

import numpy as np

rooms=np.array(['A','B'])
states = np.array(['clean','Dirty'])

def choose_rooms():
    return np.random.choice(rooms)

# print(choose_rooms())

def choose_state():
    return np.random.choice(states)

# print(choose_state())

def clean_rooms():
    room_states={}
    for x in rooms:
        room_states[str(x)]=str(choose_state())
    print(room_states)
    
    vaccum_pos=choose_rooms()
    print(f'Vaccum position is {vaccum_pos}')
    
    
    cost=0
    for x in range(len(rooms)):
        if room_states[vaccum_pos] == 'Dirty':
            print(vaccum_pos, 'is dirty.')
            print(f'cleaning {vaccum_pos}.')
        
            room_states[vaccum_pos] = 'Clean'
            print(f'{vaccum_pos} is cleaned.')
            cost+=1
        else:
            print('NO opeartion') 
    
        other_room=list(str(room) for room in set(rooms)-{vaccum_pos})
        print(other_room)
        vaccum_pos=other_room[0]
        if x == 0:
            cost+=1
        print(f'Final room states {room_states}')
        print('Both room cleaned,stop')
        print('Cost = ',cost)

    
    
clean_rooms()
print ('Saurab kunwar')

