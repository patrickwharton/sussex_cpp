import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
import sys

def question1():
    filename = "question1.csv"

    df = pd.read_csv(filename)
    x=np.linspace(1,max(df['n'])+1,100)

    ax = sns.scatterplot(x='n', y='alpha', data=df, linewidth=0)
    plt.plot(x, 0*x+1/12, 'r--', label=r'x = $\frac{1}{12}$')

    ax.set_xscale('log')
    ax.set_ylabel(r'Variance, $\alpha$')
    ax.set_xlabel('Number of random numbers, n (log scale)')
    ax.set_title(r"Variance, $\alpha$, of n random numbers between 0 and 1")
    plt.xlim(1, max(df['n'])+1)

    ax.legend()
    print("As n tends to infinity, the variance clearly tends towards 1/12")
    plt.show()
    return

if __name__ == "__main__":
    question1()
