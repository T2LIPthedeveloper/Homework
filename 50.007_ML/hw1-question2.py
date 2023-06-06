# 50.007 Machine Learning
# Homework 1 Question 2 - Perceptron Algorithm
# Name: Atul Parida
# Student ID: 1006184

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import random
import math
import csv
from pathlib import Path

# Storage of the absolute paths to the files required for Q1 
base_path = Path(__file__).parent
test_path = (base_path / "../HW1_data/2/test_1_5.csv").resolve()
train_path = (base_path / "../HW1_data/2/train_1_5.csv").resolve()

training_data = np.load(file=train_path)
testing_data = np.load(file=test_path)

# function to train perceptron model
def perceptron_train(train_data, train_labels, epochs):

    pass

def perceptron_test(test_data, test_labels, weights):

    pass

def perceptron_update(train_data, train_labels, weights):

    pass

if __name__ == "__main__":
    # train perceptron model
    # test perceptron model
    # plot results
    pass

