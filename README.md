# KUDO QUIZ

KUDO QUIZ is a simple command-line quiz management system written in C. It provides functionality for both administrators and users to manage and take quizzes.

## Features

### Administrator Features
- User Management
  - Add new users
  - Edit user details
  - Delete users
  - View user details
- Quiz Management
  - Create new quizzes
  - Edit existing quizzes
  - Delete quizzes
  - View quiz results
- Secure admin access with password protection

### User Features
- Secure login system
- Take quizzes
- View personal quiz results
- Track performance history

## Technical Details

### System Requirements
- C compiler
- Standard C libraries
- Windows OS (for clear screen and sleep functions)

### Data Structures
- Supports up to 5 users
- Maximum 10 quizzes
- Each quiz can have up to 10 questions
- Each question has 4 multiple-choice options
- Stores up to 50 quiz results

## Installation

1. Clone the repository
```bash
git clone [repository-url]
```

2. Compile the source code
```bash
gcc -o kudo_quiz main.c
```

3. Run the program
```bash
./kudo_quiz
```

## Usage

### Admin Access
1. Select "Admin" from the main menu
2. Enter the default password: `12345678`
3. Access the admin menu to manage users and quizzes

### User Access
1. Select "User" from the main menu
2. Log in with username and password
3. Take quizzes or view results

### Default User Credentials
- Username: USER1-USER5
- Password: 12345

## Security Notes
- Default admin and user passwords should be changed after first login
- The system has a three-attempt limit for login attempts

## Limitations
- Fixed maximum number of users (5)
- Fixed maximum number of quizzes (10)
- Fixed number of options per question (4)
- Basic text-based interface
- Windows-specific screen clearing functionality

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
