import os

def main():
    for i in range(1, 14):
        command = 'python3 U_{0:02d}.py'.format(i)
        os.system(command)
    
    for i in range(44, 55):
        command = 'python3 U_{0:02d}.py'.format(i)
        os.system(command)

if __name__ == "__main__":
    main()
