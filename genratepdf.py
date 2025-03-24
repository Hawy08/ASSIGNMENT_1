import csv
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas

# Function to read the CSV data
def read_csv(filename):
    student_data = {}
    scores = []
    gpa = 0
    average_grade = ''
    
    with open(filename, mode='r') as file:
        reader = csv.reader(file)
        section = ''  # To distinguish between student data and scores
        
        for row in reader:
            if not row:
                continue
            
            if row[0] == 'Unit Code':
                section = 'scores'  # Switch to reading scores
                continue
            
            if section == 'scores':
                # Ensure we capture both unit code and grade correctly
                if len(row) > 2:
                    scores.append((row[0], row[1], row[2]))  # Unit Code, Unit Name, Grade
            else:
                student_data[row[0]] = row[1]
                
            if row[0] == 'Calculated GPA':
                gpa = float(row[1])
            elif row[0] == 'Average Grade':
                average_grade = row[1]
    
    return student_data, scores, gpa, average_grade

# Function to generate PDF with aligned data
def generate_pdf(student_data, scores, gpa, average_grade, output_filename, logo_filename):
    c = canvas.Canvas(output_filename, pagesize=letter)
    width, height = letter  # Default page size is 8.5 x 11 inches
    
    # Add the logo to the center of the page
    logo_width = 133  # Adjust as necessary
    logo_height = 100  # Adjust as necessary
    logo_x = (width - logo_width) / 2  # Center the logo horizontally
    logo_y = height - logo_height - 40  # Position the logo just below the top (you can adjust this)
    
    c.drawImage(logo_filename, logo_x, logo_y, width=logo_width, height=logo_height)  # Center logo
    
    # Title
    c.setFont("Helvetica-Bold", 16)
    c.drawString(230, height - 160, "STUDENT RESULT SLIP")
    
    # Draw Student Data
    c.setFont("Helvetica", 12)
    y_position = height - 200  # Start y position for data
    
    for key, value in student_data.items():
        c.drawString(50, y_position, f"{key}: {value}")
        y_position -= 20
    
    c.drawString(50, y_position, "-----------------------------------------------------------------------------------------------------------")
    y_position -= 10
    
    # Draw Scores with Alignment
    c.setFont("Helvetica-Bold", 12)
    
    # Define column positions for alignment
    unit_code_x = 50
    unit_name_x = 150  # Add space between Unit Code and Unit Name
    grade_x = 350      # Add space between Unit Name and Grade
    
    c.drawString(unit_code_x, y_position, "Unit Code")
    c.drawString(unit_name_x, y_position, "Unit Name")
    c.drawString(grade_x, y_position, "Grade")
    y_position -= 20
    
    c.setFont("Helvetica", 12)
    
    # Iterate through the scores and print them with proper alignment
    for unit_code, unit_name, grade in scores:
        c.drawString(unit_code_x, y_position, unit_code)
        c.drawString(unit_name_x, y_position, unit_name)
        c.drawString(grade_x, y_position, grade)
        y_position -= 20
    
    c.drawString(50, y_position, "-----------------------------------------------------------------------------------------------------------")
    y_position -= 10
    
    # Draw GPA and Average Grade
    c.setFont("Helvetica-Bold", 12)
    c.drawString(50, y_position, f"Calculated GPA: {gpa:.2f}")
    y_position -= 20
    c.drawString(50, y_position, f"Average Grade: {average_grade}")
    
    # Save PDF
    c.save()

# Main function to execute the process
def main():
    # Path to your CSV file and output PDF file
    csv_filename = 'student_report.csv'
    pdf_filename = 'student_results.pdf'
    logo_filename = 'logo.jpeg'  # Replace with the path to your logo image
    
    # Read data from CSV
    student_data, scores, gpa, average_grade = read_csv(csv_filename)
    
    # Generate the PDF
    generate_pdf(student_data, scores, gpa, average_grade, pdf_filename, logo_filename)
    
    print(f"PDF results slip with centered logo generated: {pdf_filename}")

if __name__ == "__main__":
    main()
