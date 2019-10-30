import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import sys

def question3():
    if len(sys.argv) == 2:
        filename = sys.argv[1]
    else:
        filename = "craps_10000.csv"
        # print("No filename detected, assuming 'craps_10000.csv'")


    df = pd.read_csv(filename)

    new = df[df['dice_rolls'] > 20].groupby('Result')['count'].sum().reset_index()
    new['dice_rolls'] = "20+"


    grouped = df[df['dice_rolls'] <= 20].append(new, ignore_index=True, sort=True)

    ax = sns.barplot(x='dice_rolls', y='count', hue='Result', data=grouped)
    ax.set_xlabel("Number of dice rolls in game")
    ax.set_ylabel("Frequency")
    ax.set_title("Frequency of the results of a craps game")
    plt.show()

    wins_df = df[df['Result'] == 'Win'][['count', 'dice_rolls']]
    losses_df = df[df['Result'] == 'Loss'][['count', 'dice_rolls']]


    df['product'] = df['count']*df['dice_rolls']
    total_dice_rolls = df['product'].sum()
    total_trials = df['count'].sum()
    average_dice_rolls = total_dice_rolls / total_trials



    df['squares_minus_mean'] = df['count'] * ((df['dice_rolls'] - average_dice_rolls) ** 2)
    variance = df['squares_minus_mean'].sum() / total_trials
    error = variance ** 0.5/(total_trials**0.5)
    print(f"Average length of a craps game is {average_dice_rolls:.3f} +/- {error:.3f} rolls")
    # print(f"Variance is {variance}")

    # print(f"Standard deviation of length of a game is {std}")
    # print(f"Standard error of length of a game is {std/(total_trials**0.5):.4f}")

    total_wins = wins_df['count'].sum()
    total_losses = losses_df['count'].sum()
    win_chance = total_wins / total_trials
    win_variance = ((total_wins * (1-win_chance) ** 2 + total_losses * (0-win_chance) ** 2)) / total_trials
    win_error = win_variance**0.5/(total_trials**0.5)
    print(f"Chance of winning a game is {win_chance} +/- {win_error:.4f}")
    # print(f"Win std error {win_error}")


    print(f"Total wins: {total_wins}")
    print(f"Total losses: {total_losses}")

if __name__ == "__main__":
    question3()
