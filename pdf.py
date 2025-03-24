from fpdf import FPDF

# Create PDF class instance
pdf = FPDF()

# Add a page
pdf.add_page()

# Set font (Arial, 16 pt)
pdf.set_font('Arial', size=16)

# Ask user for their name
name = input("Enter your name: ")

# Add a title and the user's name
pdf.cell(200, 10, txt="Hello, " + name, ln=True, align='C')

# Save the generated PDF to a file
pdf.output("output.pdf")

print("PDF created successfully as 'output.pdf'.")
