#pragma once

// Codes from https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
// F is for foregorund, and B is for background.

// Foreground color codes.
constexpr auto F_B_R = "\x1b[1;31m"; // Foreground Bold Red.
constexpr auto F_B_B = "\x1b[1;34m"; // Foreground Bold Blue.
constexpr auto F_B_C = "\x1b[1;36m"; // Foreground Bold Cyan.
constexpr auto F_B_G = "\x1b[1;32m"; // Foreground Bold Green.
constexpr auto F_B_W = "\x1b[1;37m"; // Foreground Bold White.
constexpr auto F_B_Y = "\x1b[1;33m"; // Foreground Bold Yellow.

// Background color codes.
constexpr auto B_R = "\x1b[41m"; // Background Red.
constexpr auto B_B = "\x1b[44m"; // Background Blue.
constexpr auto B_C = "\x1b[46m"; // Background Cyan.
constexpr auto B_G = "\x1b[42m"; // Background Green.
constexpr auto B_W = "\x1b[47m"; // Background White.
constexpr auto B_Y = "\x1b[43m"; // Background Yellow.

// Non-color codes.
constexpr auto RESET = "\x1b[0m";  // Resets all text effects.
constexpr auto F_DEF = "\x1b[39m"; // Uses the default text color for the foreground.
constexpr auto B_DEF = "\x1b[49m"; // Uses the default text color for the Background.