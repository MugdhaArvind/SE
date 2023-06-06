import random
import itertools

SET=set(())

def add_ele(user_ele):
    SET.update((user_ele,))
    
    
    
def del_ele(user_ele):
    set_list=list(SET)
    if user_ele in list(SET):
        SET.remove(user_ele)
        print("Element {} successfully removed from set...\nUpdated set is {}".format(user_ele,SET))
    else:
        ("Element not found")   
        
def search_ele(user_ele):
    set_list=list(SET)
    if user_ele in list(SET):
        print("Element {} successfully found in set {}".format(user_ele,SET))
    else:
        ("Element not found")  
        
def set_size():
    set_list=list(SET)
    print("The size of given set {} is {}".format(SET,len(set_list)))
    
def display():
    print("The set is{}".format(SET))
    
def inter():
    set_b=set(())
    for i in range(random.randint(10,19)):
        temp=random.randint(1,999)
    set_b.update((temp,))
    inter=SET.intersection(set_b)
    print("Set A is {}\nSet B is {}\nTheir intersection is {}".format(SET,set_b,inter))
    
def uni():
    set_b=set(())
    for i in range(random.randint(10,19)):
        temp=random.randint(1,999)
        set_b.update((temp,))
    uni=SET.union(set_b)
    print("Set A is {}\nSet B is {}\nTheir union is {}".format(SET,set_b,uni))

def diff():
    set_b=set(())
    for i in range(random.randint(10,19)):
        temp=random.randint(1,999)
        set_b.update((temp,))
    a_b=SET.difference(set_b)
    b_a=set_b.difference(SET)
    print("Set A is {}\nSet B is {}\nThe difference set a - set b is {}\nThe difference set b - set a is {}".format(SET,set_b,a_b,b_a))
        
def sub_set(user_set,size):
    print("The subset of size {} are {}".format(size,list(map(set,itertools.combinations(user_set,size)))))
    
    
exit=0

while exit!=1:
    choice = int(input("\n1 = Add element\n2 = Remove element\n3 = Search element\n4 = Display size of SET\n5 = Display SET element\n6 = Intersect between two SETs\n7 = Union between two SETs\n8 = Difference between two SETs\n9 = Display subsets of A\n0 = Exit\nEnter choice : "))
    
    if choice==1:
        choice1 = int(input("1 = Enter manually\n2 = Add randomly\nChoice : "))
        quantity=int(input("\nEnter how many elements to add in set:"))
        if choice1==1:
              for i in range(quantity):
                ele=int(input("\nEnter elements in the set:"))
                add_ele(ele)
              print("The elements in set are {}".format(SET))
        elif choice1==2:
            for i in range(quantity):
                ele2=random.randint(1,999)
                add_ele(ele2)
            print("The elements in set are {}".format(SET))
    
    if choice==2:
        ele=int(input("\nEnter elements to remove from set:"))
        del_ele(ele)
        
    if choice==3:
        ele=int(input("\nEnter elements to search from set:"))
        search_ele(ele)
        
    if choice==4:
        set_size()
        
    if choice==5:
        display()
    
    if choice==6:
        inter()
    
    if choice==7:
        uni()  
    
    if choice==8:
        diff()  
        
    if choice==9:
        print("The given set is {}".format(SET))
        set_list=list(SET)
        n1=len(set_list)
        print("The number of subsets possible is {}".format(2**n1))
        while n1!=0:
          sub_set(SET,n1)
          n1 -=1
        if n1==0:
            print("The subset is [{}]")
            
    if choice==0 or choice>9:
        exit +=1
