import bdb
import sys
import tkinter as tk
from tkinter import filedialog


class DebuggerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Debugger with Tkinter")

        self.file_path = None
        self.breakpoints = set()
        self.breakpoints = {10, 20}

        self.frame = tk.Frame(root)
        self.frame.pack(padx=10, pady=10)

        self.btn_pick = tk.Button(self.frame, text="Pick File", command=self.pick_file)
        self.btn_pick.pack(side=tk.LEFT, padx=5)

        self.btn_run = tk.Button(self.frame, text="Run", command=self.run)
        self.btn_run.pack(side=tk.LEFT, padx=5)

    def pick_file(self):
        self.file_path = filedialog.askopenfilename(filetypes=[("Python files", "*.py")])

    def run(self):
        if self.file_path:
            debugger = MyDebugger(self.file_path, self.breakpoints)
            debugger.run()

class MyDebugger(bdb.Bdb):
    def __init__(self, file_path, breakpoints):
        super().__init__()
        self.file_path = file_path
        self.breakpoints = breakpoints

    def run(self):
        with open(self.file_path, 'r') as f:
            code = compile(f.read(), self.file_path, 'exec')
        self.set_trace()
        exec(code, globals(), locals())

    def user_line(self, frame):
        print("line", frame.f_lineno)
        if frame.f_lineno in self.breakpoints:
            self.top = tk.Toplevel()
            self.top.title("Debugger Information")
            self.text_widget = tk.Text(self.top, wrap=tk.WORD, width=40, height=10)
            self.text_widget.pack(padx=10, pady=10)
            self.show_variables(frame)
            self.show_callstack(frame)
            self.set_continue()
        else:
            self.set_step()

    def show_variables(self, frame):
        locals_str = "Local Variables:\n"
        for var, val in frame.f_locals.items():
            locals_str += f"{var}: {val}\n"
        self.text_widget.insert(tk.END, locals_str)

    def show_callstack(self, frame):
        callstack_str = "\nCall Stack:\n"
        while frame:
            callstack_str += f"{frame.f_code.co_name} at {frame.f_code.co_filename}, line {frame.f_lineno}\n"
            frame = frame.f_back
        self.text_widget.insert(tk.END, callstack_str)

root = tk.Tk()
app = DebuggerApp(root)
root.mainloop()
