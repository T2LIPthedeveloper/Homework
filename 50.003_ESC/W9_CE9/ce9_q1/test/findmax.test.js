const findmax = require('../src/findmax.js');

describe('testing findmax', () => {
    // TODO: a test that results in failure (do not compute maximum) it should fail
    test('a test that fails', () => {
        const result = findmax([1, 2, 3, 4, 5]); 
        expect(result).toBe(3);
    })
    // TODO: a test that results in error, it should throw an error that the test won't catch
    test('a test that throws error', () => {
        const result = findmax(undefined);
        expect(result).toThrow();

    })
    // TODO: a test that results in pass
    test('a test that passes', () => {
        const result = findmax([5, 4, 3, 2, 1]);
        expect(result).toBe(5);
    })
});

describe('equivalence testing for findmax', () => {
    test('empty array', () => {
        const result = findmax([]);
        expect(result).toBeUndefined(); // Since the array is empty, the result should be undefined or some other appropriate value in your implementation.
    });
    
    test('array with null values', () => {
        const result = findmax([null, null, null]);
        expect(result).toBe(0); // Since null values will be ignored in the findmax function, the result should be 0.
    });

    test('array with NaN values', () => {
        const result = findmax([NaN, NaN, NaN]);
        expect(result).toBeNaN(); // The result should be NaN since NaN values will be considered as candidates for the maximum value, and any comparison with NaN will result in NaN.
    });

    test('array with a single ordinal value', () => {
        const result = findmax([42]);
        expect(result).toBe(42); // The only value in the array is 42, so the result should be 42.
    });

    test('max value at index 0', () => {
        const result = findmax([10, 2, 4, 7]);
        expect(result).toBe(10); // The maximum value is 10, which is at index 0, so the result should be 10.
    });

    test('max value at index N-1', () => {
        const result = findmax([3, 1, 6, 9]);
        expect(result).toBe(9); // The maximum value is 9, which is at index N-1 (index 3), so the result should be 9.
    });

    test('max value not at index 0 or index N-1', () => {
        const result = findmax([5, 2, 8, 3]);
        expect(result).toBe(8); // The maximum value is 8, which is not at index 0 or index N-1, so the result should be 8.
    });

    test('array with non-numeric values', () => {
        const result = findmax(['apple', 'banana', 'orange']);
        expect(result).toBeNaN(); // Since non-numeric values will be considered as candidates for the maximum value, and any comparison with non-numeric values will result in NaN, the result should be NaN.
    });

    test('array with positive and negative values', () => {
        const result = findmax([-5, 10, -3, 7, 0]);
        expect(result).toBe(10); // The maximum value is 10, so the result should be 10.
    });

    test('array with duplicated maximum values', () => {
        const result = findmax([5, 2, 8, 8, 3]);
        expect(result).toBe(8); // The maximum value is 8, which occurs twice in the array, so the result should still be 8.
    });

    test('array with mixed data types', () => {
        const result = findmax([1, '2', 3, '4', 5]);
        expect(result).toBe(5); // The maximum value is 5, the comparison is done based on their converted numeric values, so the result should be 5.
    });

    test('array with large number of elements', () => {
        const largeArray = Array.from({ length: 100000 }, (_, index) => index);
        const result = findmax(largeArray);
        expect(result).toBe(99999); // The array contains elements from 0 to 99999, so the maximum value should be 99999.
    });
});