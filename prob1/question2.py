import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import sys

def question2():
    values = ['100', '500', '1000', '10000', '50000']
    filenames = ['dice_'+i+'.dat' for i in values]

    # create empty DataFrame of the right size
    df = pd.DataFrame(columns=['sum', 'count', 'n'])
    for i in range(len(values)):
        # iterate through each file and add it to DataFrame
        temp = pd.read_csv(filenames[i], sep='\t', names=['sum', 'count'])
        temp['n'] = int(values[i])
        df = df.append(temp, ignore_index=True)

    # pivots and prints a table of results
    table_df = df.pivot(index='sum', columns='n', values='count')
    print(table_df)

    # creating subplots
    fig, ax = plt.subplots(5, figsize=(8, 12), sharex=True)
    plt.subplots_adjust(hspace = 0.3)
    for i in range(len(values)):
        # iterate through axes and plot bar charts on each
        sns.barplot(x='sum', y='count', data=df[df['n']==int(values[i])], ax = ax[i])
        ax[i].set_xlabel(None)
        ax[i].set_ylabel(None)
        ax[i].set_title(f"Distribution of the sum of 2 dice rolled {values[i]} times")

    # Set the labels I actually want
    ax[4].set_xlabel("Sum of two dice rolls")
    ax[2].set_ylabel("Frequency")

    print("As can be seen by these graphs, the distibution centres around 7 and tends towards trianglular shape as N tends to infinity")
    plt.show()

    plt.clf()

    # makes and displays 2nd graph
    df = df.astype(int)
    df['perc'] = df['count'] / df['n']
    df['Rolls'] = df['n'].astype(str) + " rolls"

    ax = sns.lineplot(data=df, x='sum', y='perc', hue='Rolls')
    ax.set_xlabel("Sum of two dice rolls")
    ax.set_title("Distribution of the sum of two dice")
    ax.set_ylabel("Percentage frequency of two dice rolls")
    plt.show()
    plt.clf()
    return

if __name__ == "__main__":
    question2()
