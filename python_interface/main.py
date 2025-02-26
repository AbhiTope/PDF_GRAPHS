import ctypes

# Load the DLL (Adjust for Linux/macOS: use "./MyLibrary.so")
if ctypes._os.name == "nt":
    dll = ctypes.CDLL("./MyLibrary.dll")
else:
    dll = ctypes.CDLL("./MyLibrary.so")

# Define function signature (No parameters, no return type)
dll.PrintMessage.argtypes = [ctypes.c_char_p]
dll.PrintMessage.restype = None

message = "Hello From Python!".encode('utf-8')

# Call the C++ function
dll.PrintMessage(message)

