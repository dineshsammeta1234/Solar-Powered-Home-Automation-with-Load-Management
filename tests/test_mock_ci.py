import os

# Mock check for CSV data
assert os.path.exists("data/mock_sensor_data.csv"), "Mock CSV not found!"

# Simulate analysis output
with open("data/mock_sensor_data.csv") as f:
    lines = f.readlines()
    assert len(lines) > 1, "CSV file is empty!"

print("✅ Mock CI check passed (data exists & not empty)")
