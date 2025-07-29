import csv

input_file = '../data/full_weather_data.csv'
output_file = '../data/normalized_data.csv'

fields_to_keep = ["Date", "MaxTemp", "MinTemp", "MeanTemp", "Precip"]

with open(input_file, newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    normalized_rows = []

    for row in reader:
        if not row["Date"] or not row["MaxTemp"] or not row["MinTemp"]:
            continue

        normalized_row = {field: row.get(field, '') for field in fields_to_keep}
        normalized_rows.append(normalized_row)

with open(output_file, 'w', newline='') as csvfile:
    writer = csv.DictWriter(csvfile, fieldnames=fields_to_keep)
    writer.writeheader()
    writer.writerows(normalized_rows)
