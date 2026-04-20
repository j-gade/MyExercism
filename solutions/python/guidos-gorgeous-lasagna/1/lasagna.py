"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language:
https://en.wikipedia.org/wiki/Guido_van_Rossum

This is a module docstring, used to describe the functionality
of a module and its functions and/or classes.
"""


EXPECTED_BAKE_TIME = 40
PREPARATION_TIME = 2

def bake_time_remaining(elapsed_bake_time: int) -> int:
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """

    return EXPECTED_BAKE_TIME - elapsed_bake_time


def preparation_time_in_minutes(number_of_layers: int) -> int:
    """Calculate the preparation time in minutes.
    
    :param number_of_layers: int - the number of layers to prepare
    :return: int - total preparation time (in minutes) derived from the 'PREPARATION_TIME' constant
    
    Function that takes the number of layers to rpepare and returns how many minutes
    to prepare the lasagna before cooking, based on the 'PREPARATION_TIME'.
    """

    return PREPARATION_TIME * number_of_layers


def elapsed_time_in_minutes(number_of_layers: int, elapsed_bake_time: int) -> int:
    """Calculate the total elapsed time spent making the lasagna.

    :param number_of_layers: int - the number of layers added to the lasagna
    :param elapsed_bake_time: int - the number of minutes the lasagna has spent baking in the oven already

    Function that returns the total minutes you have been in the kitchen cooking — 
    your preparation time layering + the time the lasagna has spent baking in the oven.
    """

    return elapsed_bake_time + preparation_time_in_minutes(number_of_layers)
