import random

def refferences():
    dict = {
        "Alen": ["Martin", "Mario"],
        "Mario": ["Milenka", "Martin"],
        "Milenka": ["Alen", "Mario"],
        "Martin": ["Alen", "Milenka"]
        }

def get_name(name, poz):
    return dict[name][poz]

def random_picker():
    list_of_0_and_1 = [0, 1]
    return random.choice(list_of_0_and_1)

def cadou():
    myList = ["Alen", "Mario", "Martin", "Milenka"]
    for i in myList:
        x = random_picker()
        result = get_name(i, x)
        print(i + " has " + result)

cadou()
