# Electronic Voting Machine

This project is an **Electronic Voting Machine (EVM)** implemented using Arduino. The system allows users to vote for their chosen leader by pressing a button. The design ensures that each person can cast their vote only once, using a switch mechanism to prevent duplicate voting.

## Features

- **User-Friendly Interface**: Cast your vote easily by pressing a button.
- **Duplicate Prevention**: A switch ensures that one person can vote at a time, avoiding repeated votes.
- **Reliable and Secure**: Simplifies the voting process while maintaining integrity.

## How It Works

1. Each candidate is assigned a button on the voting machine.
2. The voter presses the button corresponding to their chosen candidate.
3. A switch mechanism ensures that the voting process is synchronized, allowing only one vote to be cast at a time.
4. Votes are securely recorded and can be retrieved for counting.

## Components Used

- Arduino microcontroller
- Push buttons (for voting)
- Switch (to manage voting synchronization)
- LEDs or display (optional, for feedback)

## Setup and Installation

1. **Connect the hardware**:
   - Attach the buttons for each candidate.
   - Connect the switch for vote synchronization.
   - Optionally, add LEDs or a display for real-time feedback.
2. **Upload the Code**:
   - Use the Arduino IDE to upload the code from the provided `.ino` file.
   - Ensure the correct board and COM port are selected in the IDE.

## Usage

1. Power on the device.
2. Press the button corresponding to your chosen leader to cast your vote.
3. The switch ensures that the next voter can only cast their vote after the current one finishes.

## Future Enhancements

- Add a display to show real-time vote counts or feedback after each vote.
- Implement a biometric or RFID system for voter authentication.
- Introduce remote voting functionality.

## License

This project is licensed under the MIT License. You can view or download the full license from the [LICENSE file](license.txt).
---

Happy Voting!
