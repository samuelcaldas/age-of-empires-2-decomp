FROM python:3.14-slim AS verification
ENV TZ=America/Sao_Paulo VIRTUAL_ENV=/opt/venv PATH=/opt/venv/bin:$PATH
RUN apt-get update && apt-get install -y --no-install-recommends g++-multilib git ninja-build && rm -rf /var/lib/apt/lists/*
COPY requirements.txt /tmp/requirements.txt
RUN python -m venv /opt/venv && /opt/venv/bin/pip install --no-cache-dir -r /tmp/requirements.txt flake8 pytest
WORKDIR /workspace
CMD ["python", "-m", "pytest", "-q"]
