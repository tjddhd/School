CREATE TABLE HW2I_WAREHOUSE (
   WarehouseCity  VarChar(15)   NOT NULL,
   Manager        VarChar(15)   NULL,
   SquareFeet     Integer       NULL,
   CONSTRAINT     HW2I_WAREHOUSE_PK  PRIMARY KEY (WarehouseCity)
   );
