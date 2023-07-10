const findmax = require('../src/findmax.js');

describe('testing findmax', () => {
    // TODO: a test that results in failure (do not compute maximum) it should fail
    test('a test that fails', () => {
        const result = findmax([1,2,3,4,5]);
        expect(result).toBe(4);
    })
    // TODO: a test that results in error, it should throw an error that the test won't catch
    test('a test that throws error', () => {
        const result = findmax([]);
        expect(result).toThrow();

    })
    // TODO: a test that results in pass
    test('a test that passes', () => {
        const result = findmax([5,4,3,2,1,6]);
        expect(result).toBe(6);
    })
});