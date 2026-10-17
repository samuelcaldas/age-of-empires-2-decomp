import test from 'node:test';
import assert from 'node:assert/strict';
import {dataUrl, present, historyGeometry} from '../../scripts/observability/web/view_model.mjs';

function projection() {
  return {state: 'verified', verified_cpp_bytes: 224, last_verified_cpp_bytes: 224,
    global_percent: null, measured_commit: 'a'.repeat(40), last_verified_at: '2026-10-17T12:00:00Z',
    stale: false, enrolled_units: 1, rates: {'24h': {bytes_per_hour: null}, '7d': {bytes_per_hour: null}},
    eta: {central_days: null}, history: []};
}

test('Project Pages subpath is retained', () => {
  assert.equal(dataUrl('https://example.invalid/age-of-empires-2-decomp/'),
    'https://example.invalid/age-of-empires-2-decomp/data/latest.json');
});

test('unknown percentages and rates are not rendered as zero', () => {
  const view = present(projection(), new Date('2026-10-17T12:01:00Z'));
  assert.equal(view.bytes, '224 B');
  assert.equal(view.percent, 'Unavailable');
  assert.equal(view.rate24, 'Unavailable');
  assert.equal(view.measured, 'aaaaaaaaaaaa');
});

test('client age marks old evidence stale', () => {
  const view = present(projection(), new Date('2026-10-17T13:00:00Z'));
  assert.equal(view.stale, true);
});

test('malformed payload fails explicitly', () => {
  assert.throws(() => present({state: '<script>private</script>'}), /Invalid/);
});

test('history plotting preserves literal measured values', () => {
  const points = historyGeometry([{timestamp: '2026-10-16T12:00:00Z', bytes: 0, commit: 'a'},
    {timestamp: '2026-10-17T12:00:00Z', bytes: 224, commit: 'b'}]);
  assert.equal(points.length, 2);
  assert.equal(points[1].bytes, 224);
  assert.ok(points[1].x > points[0].x);
  assert.ok(points[1].y < points[0].y);
});

test('empty history and malformed sizes do not fabricate points', () => {
  assert.deepEqual(historyGeometry([]), []);
  assert.throws(() => historyGeometry([{timestamp: 'yesterday', bytes: -1}]), /Invalid/);
});
