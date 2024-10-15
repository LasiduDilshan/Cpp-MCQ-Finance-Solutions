import pandas as pd
import matplotlib.pyplot as plt

# Load the expenses data from CSV
expenses_file = 'large_expenses.csv'
data = pd.read_csv(expenses_file, header=None, names=['Month', 'Category', 'Amount'])

# Aggregate spending by category
category_totals = data.groupby('Category')['Amount'].sum().reset_index()

# Sort categories by total spending
category_totals = category_totals.sort_values(by='Amount', ascending=False)

# Plotting
plt.figure(figsize=(10, 6))
plt.bar(category_totals['Category'], category_totals['Amount'], color='skyblue')
plt.xlabel('Categories')
plt.ylabel('Total Amount Spent')
plt.title('Total Spending by Category for the Year')
plt.xticks(rotation=45)
plt.grid(axis='y')

# Save the plot as a PNG file
plt.savefig('spending_by_category.png')

# Show the plot
plt.tight_layout()
plt.show()
