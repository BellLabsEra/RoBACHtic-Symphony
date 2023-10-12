

class StateMachine():
    def __init__(self):
        self.current_state = 0b0000
        self.next_state = 0b0000
        self.ocatveScale = 0
        self.notes_dictionary = {
            0b0000: "Idle", 0b0001: "C", 0b0010 : "C#", 0b0011 : "D",
            0b0100: "D#", 0b0101: "E", 0b0110: "E#", 0b0111: "F",
            0b1000: "F#", 0b1001: "G", 0b1010: "G#", 0b1011: "A",
            0b1100: "A#", 0b1101: "B", 0b1110: "X", 0b1111: "X",
        }
    def stateTransitions(self, nextOctave, nextNoteIndex):
        #state = 0
        if (nextNoteIndex == 0b0000):       # Terminate Early if next state is "Idle"
            return 0
        #  Ocatave 0:
        # ------------
        if (nextOctave == 0):
            print('Octave 0')
            # All possible notes on th
            if (nextNoteIndex == 0b0001 or nextNoteIndex == 0b0010):
                print("G-String")
            elif (nextNoteIndex == 0b0011 or nextNoteIndex == 0b0100 or nextNoteIndex == 0b0101
                or nextNoteIndex == 0b0110 or nextNoteIndex == 0b0111 or nextNoteIndex == 0b1000
                or nextNoteIndex == 0b1001 or nextNoteIndex == 0b1010):
                print("D-String")
            elif (nextNoteIndex == 0b1011 or nextNoteIndex == 0b1100 or nextNoteIndex == 0b1101):
                print("A-String")
        #  Ocatave 1:
        # ------------
        elif (nextOctave == 1):
            print('Octave 1')
            if (nextNoteIndex == 0b0001 or nextNoteIndex == 0b0010 or nextNoteIndex == 0b0011 or nextNoteIndex == 0b0100):
                print("A-String")
            elif (nextNoteIndex == 0b0101 or nextNoteIndex == 0b0110 or nextNoteIndex == 0b0111 or nextNoteIndex == 0b1000):
                print("E-String")
            elif (nextNoteIndex == 0b1001 or nextNoteIndex == 0b1010 or nextNoteIndex == 0b1011
                  or nextNoteIndex == 0b1100 or nextNoteIndex == 0b1101):
                print("G-String")



if __name__ == '__main__':
    print("Start State Machine Program")
    print("---------------------------")
    stateMachine = StateMachine()
    #state = stateMachine.notes_dictionary.get(0b0001)
    for index in range(0b0000, 0b1111):
        print(stateMachine.notes_dictionary.get(index))
    #octaveScale = 0

#Which is more computationally intensive switch case statements or if-else-elif