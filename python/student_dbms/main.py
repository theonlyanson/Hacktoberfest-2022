import datetime
from tkinter import *
import tkinter.messagebox as mb
from tkinter import ttk
from tkcalendar import DateEntry  # pip install tkcalendar
import sqlite3


# Create the reset function
def reset_fields():
    global name_strvar, email_strvar, contact_strvar, gender_strvar, dob, stream_strvar
    for i in ['name_strvar', 'email_strvar', 'contact_strvar', 'gender_strvar', 'stream_strvar']:
        exec(f"{i}.set('')")
    dob.set_date(datetime.datetime.now().date())


# function to display records
def display_records():
    tree.delete(*tree.get_children())
    c = connector.execute('SELECT * FROM STUDENT_MANAGEMENT')
    data = c.fetchall()
    for records in data:
        tree.insert('', END, values=records)


# Function to add record
def add_record():
    global name_strvar, email_strvar, contact_strvar, gender_strvar, dob, stream_strvar
    name = name_strvar.get()
    email = email_strvar.get()
    contact = contact_strvar.get()
    gender = gender_strvar.get()
    DOB = dob.get_date()
    stream = stream_strvar.get()
    if not name or not email or not contact or not gender or not DOB or not stream:
        mb.showerror('Error!', "Please enter all the details!")
    else:
        try:
            connector.execute('INSERT INTO Student_MANAGEMENT (NAME, EMAIL, PHONE_NO, GENDER, DOB, STREAM) VALUES (?,?,?,?,?,?)',(name, email, contact, gender, DOB, stream))
            connector.commit()
            mb.showinfo('Record inserted', f"Record of {name} is added")
            reset_fields()
            display_records()
        except:
            mb.showerror('Wrong type', 'The contact number should be 10 digits')


# Function to remove record
def remove_record():
    if not tree.selection():
        mb.showerror('Error!', 'Please select an item from the database')
    else:
        current_item = tree.focus()
        values = tree.item(current_item)
        selection = values["values"]
        tree.delete(current_item)
        connector.execute('DELETE FROM STUDENT_MANAGEMENT WHERE STUDENT_ID=%d' % selection[0])
        connector.commit()
        mb.showinfo('Done', 'The record is deleted successfully.')
        display_records()


def reset_form():
    global tree
    tree.delete(*tree.get_children())
# Creating the variables
headlabelfont = ("Calibri", 15, 'bold')
labelfont = ('Calibri', 14)
entryfont = ('Calibri', 14)

# Connecting to the Database where all information will be stored
connector = sqlite3.connect('file name')
cursor = connector.cursor()
connector.execute("CREATE TABLE IF NOT EXISTS STUDENT_MANAGEMENT (STUDENT_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, NAME TEXT, EMAIL TEXT, PHONE_NO TEXT, GENDER TEXT, DOB TEXT, STREAM TEXT)")
# Initializing the GUI window
main = Tk()
main.title('Alvas Student Management System')
main.geometry('1000x800')
main.resizable(0, 0) of db

# Creating the background and foreground color variables
lf_bg = 'SteelBlue'  # bg color for the left_frame

# Creating the StringVar or IntVar variables
name_strvar = StringVar()
email_strvar = StringVar()
contact_strvar = StringVar()
gender_strvar = StringVar()
stream_strvar = StringVar()

# Placing the components in the main window
Label(main, text="STUDENT MANAGEMENT SYSTEM", font='Arial', bg='SkyBlue').pack(side=TOP, fill=X)
left_frame = Frame(main, bg=lf_bg)
left_frame.place(x=0, y=30, height=1000, width=400)
right_frame = Frame(main, bg="gray")
right_frame.place(x=400, y=30, height=1000, width=600)

# Placing components in the left frame
Label(left_frame, text="Name", font=labelfont, bg=lf_bg).place(x=30, y=50)
Label(left_frame, text="Contact Number", font=labelfont, bg=lf_bg).place(x=30, y=100)
Label(left_frame, text="Email Address", font=labelfont, bg=lf_bg).place(x=30, y=150)
Label(left_frame, text="Gender", font=labelfont, bg=lf_bg).place(x=30, y=200)
Label(left_frame, text="Date of Birth (DOB)", font=labelfont, bg=lf_bg).place(x=30, y=250)
Label(left_frame, text="Stream", font=labelfont, bg=lf_bg).place(x=30, y=300)
Entry(left_frame, width=20, textvariable=name_strvar, font=entryfont).place(x=170, y=50)
Entry(left_frame, width=19, textvariable=contact_strvar, font=entryfont).place(x=170, y=100)
Entry(left_frame, width=19, textvariable=email_strvar, font=entryfont).place(x=170, y=150)
Entry(left_frame, width=19, textvariable=stream_strvar, font=entryfont).place(x=170, y=300)
OptionMenu(left_frame, gender_strvar, 'Male', "Female").place(x=170, y=200, width=70)
dob = DateEntry(left_frame, font=("Arial", 12), width=15)
dob.place(x=180, y=250)
Button(left_frame, text='Submit and Add Record', font=labelfont, command=add_record, width=18).place(x=80, y=380)

# Place the buttons in the left frame

Button(left_frame, text='Delete Record', font=labelfont, command=remove_record, width=15).place(x=30, y=450)
Button(left_frame, text='View Record', font=labelfont, command="view_record", width=15).place(x=200, y=450)
Button(left_frame, text='Clear Fields', font=labelfont, command=reset_fields, width=15).place(x=30, y=520)
Button(left_frame, text='Remove database', font=labelfont, command=reset_form, width=15).place(x=200, y=520)
# Placing components in the right frame

Label(right_frame, text='Students Records', font='Arial', bg='DarkBlue', fg='LightCyan').pack(side=TOP, fill=X)
tree = ttk.Treeview(right_frame, height=100, selectmode=BROWSE,
                    columns=('Stud ID', "Name", "Email Addr", "Contact No", "Gender", "Date of Birth", "Stream"))
X_scroller = Scrollbar(tree, orient=HORIZONTAL, command=tree.xview)
Y_scroller = Scrollbar(tree, orient=VERTICAL, command=tree.yview)
X_scroller.pack(side=BOTTOM, fill=X)
Y_scroller.pack(side=RIGHT, fill=Y)
tree.config(yscrollcommand=Y_scroller.set, xscrollcommand=X_scroller.set)

tree.heading('Stud ID', text='ID', anchor=CENTER)
tree.heading('Name', text='Name', anchor=CENTER)
tree.heading('Email Addr', text='Email ID', anchor=CENTER)
tree.heading('Contact No', text='Phone No', anchor=CENTER)
tree.heading('Gender', text='Gender', anchor=CENTER)
tree.heading('Date of Birth', text='DOB', anchor=CENTER)
tree.heading('Stream', text='Stream', anchor=CENTER)
tree.column('#0', width=0, stretch=NO)
tree.column('#1', width=40, stretch=NO)
tree.column('#2', width=120, stretch=NO)
tree.column('#3', width=180, stretch=NO)
tree.column('#4', width=60, stretch=NO)
tree.column('#5', width=60, stretch=NO)
tree.column('#6', width=70, stretch=NO)
tree.column('#7', width=120, stretch=NO)
tree.place(y=30, relwidth=1, relheight=0.9, relx=0)





reset_fields()

display_records()
main.update()
main.mainloop()
