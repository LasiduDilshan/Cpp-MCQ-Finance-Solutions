import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas

def load_results(file_path):
    # Load results from CSV file
    return pd.read_csv(file_path)

def generate_statistics(results):
    # Calculate statistics
    total_students = len(results)
    average_percentage = results['Percentage'].mean()
    std_dev = results['Percentage'].std()
    
    # Calculate z-scores
    results['Z-Score'] = (results['Percentage'] - average_percentage) / std_dev
    
    # Get the count of correct answers
    correct_answer_counts = results['Correct Answers'].value_counts().sort_index()

    return total_students, average_percentage, std_dev, results, correct_answer_counts

def generate_statistics_pdf(total_students, average_percentage, std_dev, results, correct_answer_counts, output_file):
    # Create PDF
    pdf = canvas.Canvas(output_file, pagesize=letter)
    pdf.setFont("Helvetica", 12)
    
    # Write basic statistics
    pdf.drawString(100, 750, "MCQ Results Statistics")
    pdf.drawString(100, 730, f"Total Students: {total_students}")
    pdf.drawString(100, 710, f"Average Percentage: {average_percentage:.2f}%")
    pdf.drawString(100, 690, f"Standard Deviation: {std_dev:.2f}")

    # Write Z-Scores
    pdf.drawString(100, 670, "Z-Scores:")
    y_position = 650
    for index, row in results.iterrows():
        pdf.drawString(100, y_position, f"{row['Name']} (ID: {row['ID']}): {row['Z-Score']:.2f}")
        y_position -= 15
    
    # Save the PDF
    pdf.save()

def generate_visualization(correct_answer_counts):
    # Create a bar chart for correct answers distribution
    plt.figure(figsize=(10, 6))
    plt.bar(correct_answer_counts.index, correct_answer_counts.values, color='skyblue')
    plt.title('Distribution of Correct Answers')
    plt.xlabel('Correct Answers')
    plt.ylabel('Number of Students')
    plt.xticks(rotation=45)
    plt.tight_layout()

    # Save visualization as an image
    plt.savefig('correct_answer_distribution.png')
    plt.close()

def main():
    results_file = 'results.csv'  # Path to the results.csv
    output_pdf_file = 'statistics.pdf'

    # Load results
    results = load_results(results_file)

    # Generate statistics
    total_students, average_percentage, std_dev, results_with_z_score, correct_answer_counts = generate_statistics(results)

    # Generate PDF with statistics
    generate_statistics_pdf(total_students, average_percentage, std_dev, results_with_z_score, correct_answer_counts, output_pdf_file)

    # Generate visualization
    generate_visualization(correct_answer_counts)

    print(f"Statistics generated. Results saved to '{output_pdf_file}' and visualization as 'correct_answer_distribution.png'.")

if __name__ == "__main__":
    main()
