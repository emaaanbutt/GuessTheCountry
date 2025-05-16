# 🌍✈️ GUESS THE COUNTRY - C++ TERMINAL GAME 🎮

> 🧠🌎 Can you guess the country just by its capital? Let's find out!

Welcome to **Guess the Country**, a thrilling C++ trivia game where players must identify countries using capital city hints — all while the clock ticks and lives run out 😨. Play solo or grab a friend for the ultimate geography showdown! 🧍👬

---

## 🎮 GAME MODES

### 🧍 SINGLE PLAYER MODE
- Guess countries based on their capital before you run out of lives ❤️
- Earn points for correct guesses (+15) and lose points for wrong ones (-5, no negative score)
- Game ends when lives = 0 or you enter `0` to quit.

### 👬 DOUBLE PLAYER MODE
- Take turns guessing — one player at a time
- Separate lives and scores for both players
- See who’s the real geography master! 🌐👑

---

## 🗺️ CONTINENTS & LEVELS

Each round randomly selects a continent:
- Asia 🌏
- Europe 🌍
- Africa 🌍
- North America 🌎
- South America 🌎
- Oceania 🌊

Difficulty Levels:
- **Easy 🤙** – Beginner-friendly countries
- **Medium 😨** – Trickier names & less-known capitals
- **Hard 😡** – Geography PhD level 💀

---

## 📜 HOW TO PLAY

1. Run the game.
2. Choose a game mode (Single/Double).
3. Select your difficulty.
4. A capital will appear as a hint. Type the correct country name!
5. Type `0` anytime to exit mid-game. Points will be shown.
6. Lives drop when you're wrong 💔. Don’t let them hit zero!

---

## 💾 FEATURES

- 🎯 Random continent and country every round!
- 🕹️ Real-time guessing with input timer
- ❤️ Lives & scoring system
- 💾 Highscore tracking saved to `score.txt`
- 🔁 Replay option on game over

---


## 🧠 FUN FACT

All country and capital data is stored in **binary search trees** per level and continent. The game picks a random node each time, so no two sessions are ever the same 🔁🌐!

---

## ⚠️ NOTES

- Use **UTF-8 compatible terminals** for emoji support 😄
- Make sure `score.txt` is in the same directory, or it’ll be auto-created
- Developed for learning + chaotic vibes — feel free to add sounds, animations, or flags if you're feeling ✨fancy✨

---


## 🏁 READY TO PLAY?

Compile and run:
```bash
g++ main.cpp -o guessGame
./guessGame
```
