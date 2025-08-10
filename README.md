# 📦 Huffman File Compressor (C++ + Web UI)

This is a file compression system that combines:
- 💻 Advanced *C++* for actual Huffman compression.
- 🌐 A browser UI built with HTML, CSS, and JavaScript.
- 🎯 Demonstrates real-world compression and file handling.

## 🔧 How It Works

### Web:
- Simulates compression with an intuitive interface.
- Users can upload a text file and see estimated compression stats.

### C++:
- Uses *Huffman Encoding* to compress a .txt file to a binary .bin.
- Efficient file I/O and data structures (heap, map, bit manipulation).

## 📂 Structure

- index.html – Frontend UI
- style.css – Web styling
- script.js – Compression simulation logic
- compressor.cpp – Main Huffman encoding logic

## 🧪 How to Run

### Web:
Open index.html in your browser.

### C++:
Compile and run:

```bash
g++ compressor.cpp -o compressor
./compressor
