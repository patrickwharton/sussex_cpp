import pandas as pd

df = pd.read_csv('craps_used.csv')


new = df[df['dice_rolls'] > 20].groupby('Result')['count'].sum().reset_index()
new['dice_rolls'] = "20+"


grouped = df[df['dice_rolls'] <= 20].append(new, ignore_index=True, sort=True)

df = grouped.pivot(values='count', index='Result', columns='dice_rolls')
# print(df.head())
df.to_csv('new.csv', index=False)
