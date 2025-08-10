<script>
function simulateCompression() {
  const input = document.getElementById("fileInput");
  const result = document.getElementById("result");

  if (!input.files.length) {
    result.innerHTML = "Please select a file.";
    return;
  }

  const file = input.files[0];

  const reader = new FileReader();
  reader.onload = () => {
    const text = reader.result;
    const originalSize = text.length;

    // Fake Huffman compression (simulate 40–60% size reduction)
    const compressedSize = Math.floor(originalSize * 0.45);

    result.innerHTML = `
      <p><strong>Original Size:</strong> ${originalSize} bytes</p>
      <p><strong>Estimated Compressed Size:</strong> ${compressedSize} bytes</p>
      <p><strong>Compression Ratio:</strong> ${(100 * compressedSize / originalSize).toFixed(2)}%</p>
      <p><em>Actual compression is done by C++ (run from terminal).</em></p>
    `;
  };

  reader.readAsText(file);
}
</script>