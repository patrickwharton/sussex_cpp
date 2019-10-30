import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import sys

def question3():
    if len(sys.argv) == 2:
        filename = sys.argv[1]
    else:
        filename = "craps.csv"
        # print("No filename detected, assuming 'craps_10000.csv'")


    df = pd.read_csv(filename)

    new = df[df['dice_rolls'] > 20].groupby('Result')['count'].sum().reset_index()
    new['dice_rolls'] = "20+"


    grouped = df[df['dice_rolls'] <= 20].append(new, ignore_index=True, sort=True)

    ax = sns.barplot(x='dice_rolls', y='count', hue='Result', data=grouped, palette=[sns.xkcd_rgb['cerulean'], sns.xkcd_rgb['vermillion']])
    ax.set_xlabel("Number of dice rolls in game")
    ax.set_ylabel("Frequency")
    ax.set_title("Frequency of the results of a craps game")

    # for index, row in grouped.iterrows():
    #     ax.text(row.dice_rolls, row['count'], row['count'], color='black', rotation=90)


    plt.show()
    plt.clf()
    plt.close()
    plt.cla()

    wins_df = grouped[grouped['Result'] == 'Win'][['count', 'dice_rolls']].reset_index()
    losses_df = grouped[grouped['Result'] == 'Loss'][['count', 'dice_rolls']].reset_index()
    total_wins = wins_df['count'].sum()
    total_losses = losses_df['count'].sum()

    df['product'] = df['count']*df['dice_rolls']
    total_dice_rolls = df['product'].sum()
    total_trials = df['count'].sum()
    average_dice_rolls = total_dice_rolls / total_trials

    df['sum_squared_diff'] = df['count'] * ((df['dice_rolls'] - average_dice_rolls) ** 2)
    variance = df['sum_squared_diff'].sum() / total_trials
    error = variance ** 0.5/(total_trials**0.5)
    print(f"Mean length of a craps game is {average_dice_rolls:.3f} +/- {error:.3f} rolls")


    win_chance = total_wins / total_trials
    win_variance = ((total_wins * (1-win_chance) ** 2 + total_losses * (0-win_chance) ** 2)) / total_trials
    win_error = win_variance**0.5/(total_trials**0.5)
    print(f"Chance of winning a game is {win_chance:.4f} +/- {win_error:.4f}")

    max_rolls = 21
    ratio = []
    for i in range(max_rolls):
        try:
            wins = wins_df['count'][i]
        except KeyError:
            wins = 0
        try:
            losses = losses_df['count'][i]
        except KeyError:
            if wins == 0:
                ratio.append(None)
                continue
            else:
                ratio.append(1)
                continue
        try:
            ratio.append(wins/(wins+losses))
        except ZeroDivisionError:
            ratio.append(1)

    ax2 = sns.lineplot(x=range(1, len(ratio)+1), y=ratio)
    xlabels = [str(i) for i in range(1, len(ratio))] + ['20+']
    ax2.set_xticklabels(xlabels)
    ax2.set_xticks([i for i in range(1, len(ratio)+1)])
    ax2.set_xlim(0,len(ratio)+1)
    ax2.set_ylim(0,1)
    ax2.set_xlabel("Number of dice rolls")
    ax2.set_ylabel("Chance of winning")
    ax2.set_title("Chances of winning craps as the game length increases")
    plt.show()


    # print(f"Total wins: {total_wins}")
    # print(f"Total losses: {total_losses}")

if __name__ == "__main__":
    question3()
