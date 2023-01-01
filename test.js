const fs = require('fs-extra');

async function main() {
    await fs.writeFile('a.txt', 'a');
    const fn = require('./index');
    await fn(['a.txt']);
}

main().catch((err) => {
    console.error(err);
    process.exit(1);
});
