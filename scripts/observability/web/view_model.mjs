const STATES = new Set(['verified', 'failed', 'blocked', 'pending', 'running', 'unavailable']);

/** Resolve data relative to Project Pages, never to the domain root. */
export function dataUrl(base) {
  return new URL('data/latest.json', base).href;
}

function number(value, suffix = '') {
  if (value === null || value === undefined) return 'Unavailable';
  if (typeof value !== 'number' || !Number.isFinite(value)) throw new Error('Invalid numeric metric');
  return new Intl.NumberFormat('en', {maximumFractionDigits: 2}).format(value) + suffix;
}

/** Format existing metrics without recalculating percentages, rates or ETA. */
export function present(projection, now = new Date()) {
  if (!projection || !STATES.has(projection.state) || !projection.rates || !projection.eta) {
    throw new Error('Invalid projection');
  }
  const age = projection.last_verified_at ? now - new Date(projection.last_verified_at) : Infinity;
  if (Number.isNaN(age)) throw new Error('Invalid measurement time');
  return {
    bytes: number(projection.verified_cpp_bytes, ' B'),
    historicalBytes: number(projection.last_verified_cpp_bytes, ' B'),
    percent: number(projection.global_percent, '%'),
    rate24: number(projection.rates['24h']?.bytes_per_hour, ' B/h'),
    rate7: number(projection.rates['7d']?.bytes_per_hour, ' B/h'),
    eta: number(projection.eta.central_days, ' days'),
    measured: projection.measured_commit?.slice(0, 12) || 'Unknown',
    head: projection.head_commit?.slice(0, 12) || 'Unknown',
    sourceHead: projection.source_head_commit?.slice(0, 12) || 'Unknown',
    verifiedAt: projection.last_verified_at || 'No successful verification',
    state: projection.state, stale: projection.stale || age > 900000 || age < 0,
    enrolled: String(projection.enrolled_units ?? 0),
    reason: projection.reason || '',
  };
}

/** Compute only drawing coordinates; literal observations remain attached. */
export function historyGeometry(history) {
  if (!Array.isArray(history)) throw new Error('Invalid history');
  if (!history.length) return [];
  const times = history.map(point => Date.parse(point.timestamp));
  if (times.some(value => !Number.isFinite(value)) || history.some(point => !Number.isSafeInteger(point.bytes) || point.bytes < 0)) {
    throw new Error('Invalid history values');
  }
  const first = Math.min(...times), last = Math.max(...times);
  const maximum = Math.max(1, ...history.map(point => point.bytes));
  return history.map((point, index) => ({...point,
    x: first === last ? 400 : 68 + (times[index] - first) / (last - first) * 660,
    y: 210 - point.bytes / maximum * 180, maximum,
  }));
}
