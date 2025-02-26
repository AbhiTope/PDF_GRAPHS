import ctypes

# Load the DLL (Adjust for Linux/macOS: use "./MyLibrary.so")
dll = ctypes.CDLL("./MyLibrary.dll")

# Define function signature (No parameters, no return type)
dll.PrintMessage.argtypes = []
dll.PrintMessage.restype = None

# Call the C++ function
dll.PrintMessage()

