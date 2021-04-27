var used, i, heap, a, b, c;
var total = 0;

console.log("VANILLA\n");

used = 0;
for (i = 0; i < 15; i++) {
    heap = process.memoryUsage();
    used += heap.heapUsed;
    total += used;
    console.log("Iteration " + (i + 1) + ": " + (used / 1e+6).toFixed(1) + " MB");
}

console.log("\n\nLOGIC STATEMENTS\n");

used = 0;
for (i = 0; i < 15; i++) {
    a = Math.floor(Math.random() * 10);
    b = Math.floor(Math.random() * 10);
    c = Math.floor(Math.random() * 10);

    if (a == b && a == c || a != b || a != c && a == b) {
        heap = process.memoryUsage();
    } else {
        heap = process.memoryUsage();
    }

    used += heap.heapUsed;
    total += used;
    console.log("Iteration " + (i + 1) + ": " + (used / 1e+6).toFixed(1) + " MB");
}

console.log("\n\nARITHMETIC OPERATIONS\n");

used = 0;
for (i = 0; i < 15; i++) {
    a = (((Math.floor(Math.random() * 10) + 3) * 8) / 4) - (6 % Math.sin(Math.PI / 23));
    b = Math.cos((a * -1) / Math.sin(5 + 2));
    c = Math.sqrt(((b % 3) + (a + 5) - b)) / Math.pow(4, 3 * (2 * 9));

    heap = process.memoryUsage();
    used += heap.heapUsed;
    total += used;
    console.log("Iteration " + (i + 1) + ": " + (used / 1e+6).toFixed(1) + " MB");
}

console.log("\n\nTOTAL USAGE: " + (total / 1e+6).toFixed(1) + " MB");