import {historyGeometry} from './view_model.mjs';

const XMLNS = 'http://www.w3.org/2000/svg';

function element(name, attributes = {}) {
  const node = document.createElementNS(XMLNS, name);
  for (const [key, value] of Object.entries(attributes)) {
    node.setAttribute(key, String(value));
  }
  return node;
}

export function renderChart(container, tooltip, history, onSelect = () => {}) {
  while (container.firstChild) container.removeChild(container.firstChild);
  if (!history.length) return;
  const points = historyGeometry(history);

  // Baselines and hairline grid (recessive)
  container.appendChild(element('line', {x1: 68, y1: 210, x2: 740, y2: 210, class: 'grid'}));
  container.appendChild(element('line', {x1: 68, y1: 30, x2: 740, y2: 30, class: 'grid'}));

  const yZero = element('text', {x: 20, y: 214});
  yZero.textContent = '0 B';
  container.appendChild(yZero);

  const yMax = element('text', {x: 20, y: 34});
  yMax.textContent = `${points[0].maximum} B`;
  container.appendChild(yMax);

  // Single series polyline: thin 2px mark
  const polyline = element('polyline', {
    points: points.map(p => `${p.x.toFixed(1)},${p.y.toFixed(1)}`).join(' '),
    class: 'series'
  });
  container.appendChild(polyline);

  // Crosshair
  const crosshair = element('line', {
    x1: points[points.length - 1].x, y1: 20,
    x2: points[points.length - 1].x, y2: 220,
    class: 'crosshair'
  });
  container.appendChild(crosshair);

  // Points with surface rings (r=4, stroke=2, target >= 24px)
  points.forEach((point, index) => {
    // 24px invisible hit target
    const target = element('circle', {
      cx: point.x, cy: point.y, r: 12, fill: 'transparent',
      tabindex: 0, role: 'button',
      'aria-label': `${point.bytes} bytes observed at ${point.timestamp}`
    });
    const mark = element('circle', {
      cx: point.x, cy: point.y, r: 4, class: 'point'
    });

    const activate = () => {
      crosshair.setAttribute('x1', String(point.x));
      crosshair.setAttribute('x2', String(point.x));
      tooltip.textContent = `Observed ${point.bytes} B at ${point.timestamp} (commit ${point.commit.slice(0, 8)})`;
      onSelect(point);
    };

    target.addEventListener('mouseenter', activate);
    target.addEventListener('focus', activate);
    container.appendChild(mark);
    container.appendChild(target);
  });

  // Direct label at endpoint (selective)
  const lastPoint = points[points.length - 1];
  const directLabel = element('text', {
    x: Math.min(680, lastPoint.x + 8),
    y: Math.max(25, lastPoint.y - 6),
    class: 'direct-label'
  });
  directLabel.textContent = `${lastPoint.bytes} B`;
  container.appendChild(directLabel);
}
