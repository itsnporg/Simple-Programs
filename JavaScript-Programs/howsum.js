const howSum = (targetSum, nums) =>
{
    if (targetSum < 0)
    {
        return null;
    }
    if (targetSum === 0)
    {
        return [];
    }

    for (let num of nums)
    {
        const remainder = targetSum - num;
        const remainderResult = howSum(remainder, nums);
        if (remainderResult !== null)
        {
            return [... remainderResult, num ];
        }
    }
    return null;
}

console.log(howSum(7, [ 2, 3, 1 ]));