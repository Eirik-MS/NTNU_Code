

def write_to_file(filename, text):
    """Write the text to the file with the given filename."""
    with open(filename, 'w') as f:
        f.write(text)

def read_from_file(filename):
    """Read the text from the file with the given filename."""
    with open(filename, 'r') as f:
        return f.read()
    
def main():
    print("Do you want to read or write to a file?")
    choice = input("Your choice: ") 
    match choice:
        case "read":
            filename = input("Enter the filename: ")
            print(read_from_file(filename))
        case "write":
            filename = input("Enter the filename: ")
            text = input("Enter the text: ")
            write_to_file(filename, text)
        case "done": 
            print("Goodbye!")
            return 0
        case _:
            print("Invalid choice, please write lowercase 'read' or 'write' or 'done'")
    main()
main()


