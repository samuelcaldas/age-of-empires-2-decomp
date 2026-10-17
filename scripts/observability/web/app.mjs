import {dataUrl, present} from './view_model.mjs';
import {renderChart} from './chart.mjs';

function setNotice(message, state = 'info') {
  const el = document.getElementById('notice');
  if (el) {
    el.textContent = message;
    el.className = `notice notice-${state}`;
  }
}

function updateTable(history) {
  const tbody = document.getElementById('history-table');
  if (!tbody) return;
  while (tbody.firstChild) tbody.removeChild(tbody.firstChild);
  history.slice(-100).reverse().forEach(row => {
    const tr = document.createElement('tr');
    const tdTime = document.createElement('td');
    tdTime.textContent = row.timestamp;
    const tdCommit = document.createElement('td');
    tdCommit.textContent = row.commit.slice(0, 8);
    const tdBytes = document.createElement('td');
    tdBytes.textContent = `${row.bytes} B`;
    const tdSeries = document.createElement('td');
    tdSeries.textContent = row.series_id.slice(0, 8);
    tr.append(tdTime, tdCommit, tdBytes, tdSeries);
    tbody.appendChild(tr);
  });
}

function applyView(projection) {
  const view = present(projection);
  document.getElementById('edition').textContent = projection.edition || 'UNKNOWN';
  document.getElementById('bytes').textContent = view.bytes;
  document.getElementById('enrolled').textContent = view.enrolled;
  document.getElementById('state').textContent = view.state + (view.reason ? ` (${view.reason})` : '');
  document.getElementById('percent').textContent = view.percent;
  document.getElementById('historicalBytes').textContent = view.historicalBytes;
  document.getElementById('rate24').textContent = view.rate24;
  document.getElementById('rate7').textContent = view.rate7;
  document.getElementById('eta').textContent = view.eta;
  document.getElementById('sourceHead').textContent = view.sourceHead;
  document.getElementById('measured').textContent = view.measured;
  document.getElementById('verifiedAt').textContent = view.verifiedAt;

  if (view.stale) {
    setNotice(`Evidence is stale or unverified on default branch HEAD (${view.state})`, 'warning');
  } else if (view.state === 'verified') {
    setNotice(`Verified matching C++ codebase slice (${view.bytes})`, 'success');
  } else {
    setNotice(`Status: ${view.state} - ${view.reason || 'No current verification'}`, 'info');
  }

  const chartSvg = document.getElementById('history-chart');
  const tooltip = document.getElementById('chart-tooltip');
  const chartNote = document.getElementById('chart-note');
  if (projection.history && projection.history.length > 0) {
    if (chartNote) chartNote.style.display = 'none';
    renderChart(chartSvg, tooltip, projection.history);
    updateTable(projection.history);
  } else {
    if (chartNote) chartNote.style.display = 'block';
  }
}

async function fetchLatest() {
  try {
    const url = dataUrl(window.location.href);
    const resp = await fetch(url, {cache: 'no-cache'});
    if (!resp.ok) {
      setNotice(`Failed to fetch latest metrics (HTTP ${resp.status})`, 'error');
      return;
    }
    const data = await resp.json();
    if (!data.projection) {
      setNotice('Malformed metric payload', 'error');
      return;
    }
    applyView(data.projection);
  } catch (err) {
    setNotice(`Network or parse error: ${err.message}`, 'error');
  }
}

function initTheme() {
  const btn = document.getElementById('theme');
  if (!btn) return;
  const current = localStorage.getItem('theme') || 'auto';
  if (current !== 'auto') {
    document.documentElement.setAttribute('data-theme', current);
  }
  btn.addEventListener('click', () => {
    const active = document.documentElement.getAttribute('data-theme');
    const next = active === 'dark' ? 'light' : 'dark';
    document.documentElement.setAttribute('data-theme', next);
    localStorage.setItem('theme', next);
  });
}

function init() {
  initTheme();
  fetchLatest();
  setInterval(fetchLatest, 15000);
}

if (typeof document !== 'undefined') {
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }
}
