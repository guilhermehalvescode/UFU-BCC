function mwisStub(v, pos) {
  if (v.length - pos <= 2) return v[pos] ?? 0;

  if (v.length - pos === 3) return v[pos] + v[pos + 3];

  const sol1 = mwis(v, pos + 1);
  const sol2 = mwis(v, pos + 2);
  return v[pos] + Math.max(sol1, sol2);
}

function mwis(v) {
  return Math.max(mwisStub(v, 0), mwisStub(v, 1));
}

console.log(mwis([1, 4, 5, 4]));
