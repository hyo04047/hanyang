# -*- coding: utf-8 -*-

import random

# 행맨 그림
HANGMANPICTURE = ['''

    +---+
    |   |
        |
        |
        |
        |
==============''', '''

    +---+
    |   |
    o   |
        |
        |
        |
==============''', '''

    +---+
    |   |
    o   |
    |   |
        |
        |
==============''', '''

    +---+
    |   |
    o   |
   /|   |
        |
        |
==============''', '''

    +---+
    |   |
    o   |
   /|\  |
        |
        |
==============''', '''

    +---+
    |   |
    o   |
   /|\  |
   /    |
        |
==============''', '''

    +---+
    |   |
    o   |
   /|\  |
   / \  |
        |
==============''']

# 단어 리스트
words = 'ant baboon badger bat bear beaver camel cat clam cobra cougar coyote crow deer dog donkey duck eagle ferret fox frog goat goose hawk lion lizard llama mole monkey moose mouse mule newt otter owl panda parrot pigeon python rabbit ram rat raven rhino salmon seal shark sheep skunk sloth snake spider stork swan tiger toad trout turkey turtle weasle whale wolf wombat zebra'.split()

# 랜덤 단어 정하기
def getRandomWord(wordlist):
    word_index = random.randint(0, len(wordlist) - 1)
    return wordlist[word_index]

# 그림 + 알파벳 print
def displayboard(HANGMANPICTURE, missedLetters, correctLetters, secretWord):
    print(HANGMANPICTURE[len(missedLetters)])
    print()

    print('Missed letters : ', end = " "),
    for letter in missedLetters:
        print(letter, end = " ")

    print()

    print('Secret word : ', end = " ")

    blanks = '_' * len(secretWord)

    for i in range(len(secretWord)):
        if secretWord[i] in correctLetters:
            blanks = blanks[:i] + secretWord[i] + blanks[i+1:]

    for letter in blanks:
        print(letter, end = " ")

    print()

# 알파벳 입력 받기
def getGuess(alreadyGuessed):
    while True:
        print('Guess a letter.')
        guess = input()
        guess = guess.lower() # 소문자로 통일
        if len(guess) != 1 : # 한글자 이상 입력 예외처리
            print('Please enter a single letter.')
        elif guess in alreadyGuessed: # 이미 입력한 글자 예외처리
            print('You have already guessed that letter. Choose again.')
        elif guess not in 'abcdefghijklmnopqrstuvwxyz': # 알파벳 이외 예외처리
            print('Please enter a AlPHABET.')
        else:
            return guess

# 다시 시작
def playAgain():
    print('Do you want to play again? (yes or no)')
    return input().lower().startswith('y')

# --------메인--------
print('H A N G M A N')
missedLetters = ''
correctLetters = ''
secretWord = getRandomWord(words)
gameIsDone = False

# 게임 반복 위해 while문
while True:
    displayboard(HANGMANPICTURE, missedLetters, correctLetters, secretWord)
    guess = getGuess(missedLetters + correctLetters)

    if guess in secretWord:
        correctLetters = correctLetters + guess
        allfounded = True
        for i in range(len(secretWord)):
            if secretWord[i] not in correctLetters:
                allfounded = False
                break
        if allfounded:
            print('Good job!')
            gameIsDone = True
    else:
        missedLetters = missedLetters + guess

        if len(missedLetters) == len(HANGMANPICTURE) - 1:
            displayboard(HANGMANPICTURE, missedLetters, correctLetters, secretWord)
            print('Game Over.')
            gameIsDone = True

        if gameIsDone:
            if playAgain():
                missedLetters = ''
                correctLetters = ''
                gameIsDone = False
                secretWord = getRandomWord(words)
            else:
                break
