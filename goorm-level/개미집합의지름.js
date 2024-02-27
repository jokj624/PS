// Run by Node.js
const readline = require('readline');

function solution(arr, n, d) {
	let count = 0;
	let l = 0, r = 0;
	arr.sort((a, b) => a - b);
	
	while ((l < n) && (r < n)) {
		if (arr[r] - arr[l] <= d) {
			r++;
		} else {
			count++;
			l++;
			r++;
		}
	}
	
	return count;
}

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let count = 0;
	let n = null, d = 0;
	let arr = [];
	for await (const line of rl) {
		if (!count) {
			const line1 = line.split(' ');
			n = +line1[0];
			d = +line1[1];
		} else {
			arr = line.split(' ').map(el => +el);
		}
		
		count++;
		
		if (count > 1) {
			rl.close();
		}
	}
	const result = solution(arr, n, d);
	
	console.log(result);
	process.exit();
})();

