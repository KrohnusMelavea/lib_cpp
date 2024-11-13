INSERT INTO ShiftLogs (
 ShiftLogID, 
 CaregiverID, 
 ClockInTime
) 
SELECT 
 ShiftLogID, 
 nested_query_1.CaregiverID, 
 NOW() 
FROM (
 SELECT 
  CaregiverID 
 FROM (
  SELECT 
   '026af4d6-3596-4ab3-b64f-b4856ebe8165' AS CaregiverID, 
   1 AS SortOrder 
  FROM CaregiverShifts 
  WHERE 
   CaregiverShifts.CaregiverID = '026af4d6-3596-4ab3-b64f-b4856ebe8165' 
    AND 
   CaregiverShifts.PatientID = '42790224-5b78-498f-9755-9722b6cfd3ac' 
    AND
   CaregiverShifts.ShiftStart < NOW()
    AND 
   NOW() < CaregiverShifts.ShiftEnd
  UNION
  SELECT 
   NULL, 
   2
 ) AS nested_query_0 
 ORDER BY SortOrder 
 LIMIT 1
) AS nested_query_1 
 INNER JOIN 
(
 SELECT
  ShiftLogID, 
  CaregiverID
 FROM (
  SELECT 
   ShiftLogID, 
   '026af4d6-3596-4ab3-b64f-b4856ebe8165' AS CaregiverID, 
   0 AS SortOrder 
  FROM ShiftLogs 
  WHERE ShiftLogs.ClockOutTime IS NULL 
  UNION 
  SELECT 
   NULL, 
   NULL, 
   1 
  FROM ShiftLogs 
  WHERE 
   ShiftLogs.CaregiverID = '026af4d6-3596-4ab3-b64f-b4856ebe8165' 
    AND 
   ShiftLogs.ClockOutTime IS NOT NULL 
  UNION
  SELECT 
   uuid(), 
   '026af4d6-3596-4ab3-b64f-b4856ebe8165', 
   2
 ) AS nested_query_2 
 ORDER BY nested_query_2.SortOrder 
 LIMIT 1
) AS nested_query_3 
 ON nested_query_3.CaregiverID = nested_query_1.CaregiverID 
ON DUPLICATE KEY UPDATE 
 ShiftLogs.ClockOutTime = NOW();