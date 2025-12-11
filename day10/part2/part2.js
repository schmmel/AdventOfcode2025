const { init } = require('z3-solver');
const { input } = require('./input');

(async () => {
    const { Context } = await init();
    const context = new Context('main');
    const { Int, Optimize } = context;

    const testinput = `[.##.] (3) (1,3) (2) (2,3) (0,2) (0,1) {3,5,4,7}
[...#.] (0,2,3,4) (2,3) (0,4) (0,1,2) (1,2,3,4) {7,5,12,7,2}
[.###.#] (0,1,2,3,4) (0,3,4) (0,1,2,4,5) (1,2) {10,11,11,5,10,5}`;

    let buttons = [];
    let joltage = [];

    const lines = input.split('\n').map(line => line.trim()).filter(line => line);

    let i = 0;
    lines.map(line => {
        const noBrackets = line.replace(/\[.*?\]/g, '').trim();

        buttons[i] = [...noBrackets.matchAll(/\((.*?)\)/g)].map(match =>
            match[1].split(',').map(Number)
        );

        const finalValuesMatch = line.match(/\{(.*?)\}/);
        joltage[i] = finalValuesMatch ? finalValuesMatch[1].split(',').map(Number) : [];

        i++;
    })

    async function leastPresses(buttons, joltage) {
        const buttonCount = buttons.length;
        const joltageCount = joltage.length;

        const b = Array.from({ length: buttonCount }, (_, i) => Int.const(`b${i}`));

        const solver = new Optimize();

        b.forEach(bi => solver.add(bi.ge(Int.val(0))));

        for (let i = 0; i < joltageCount; i++) {
            const affectingButtons = [];
            for (let j = 0; j < buttonCount; j++) {
                if (buttons[j].includes(i)) {
                    affectingButtons.push(b[j]);
                }
            }

            if (affectingButtons.length === 0) continue;

            let sumExpr = affectingButtons[0];
            for (let k = 1; k < affectingButtons.length; k++) {
                sumExpr = sumExpr.add(affectingButtons[k]);
            }

            solver.add(sumExpr.eq(Int.val(joltage[i])));
        }

        let totalPresses = b[0];
        for (let k = 1; k < b.length; k++) {
            totalPresses = totalPresses.add(b[k]);
        }

        solver.minimize(totalPresses);

        const result = await solver.check();
        if (result === 'sat') {
            const model = solver.model();
            const presses = b.map(bi => model.get(bi).value());
            console.log('button presses:', presses.map(x => x.toString()));
            const total = presses.reduce((a, c) => a + c, 0n);
            console.log('total presses:', total.toString());
            return total;
        } else {
            console.log('no solution found??');
            return 0;
        }
    }

    let totalTotal = 0n;

    for (let i = 0; i < buttons.length; i++) {
        console.log(`\nLine ${i + 1}`);
        const total = await leastPresses(buttons[i], joltage[i]);
        totalTotal += total;
    }

    console.log("total total", totalTotal);
})();