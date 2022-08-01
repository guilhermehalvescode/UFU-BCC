function mwisStub(v, pos) {
  if (v.length - pos <= 2) return v[pos] ?? 0;

  if (v.length - pos === 3) return v[pos] + v[pos + 2];

  const sol1 = mwisStub(v, pos + 2);
  const sol2 = mwisStub(v, pos + 3);

  return v[pos] + Math.max(sol1, sol2);
}

function mwis(v) {
  return Math.max(mwisStub(v, 0), mwisStub(v, 1));
}

console.log(mwis([1, 4, 5, 4]));
