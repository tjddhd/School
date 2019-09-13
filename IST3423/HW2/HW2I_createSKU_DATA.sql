CREATE TABLE HW2I_SKU_DATA (
   SKU              Integer         NOT NULL,
   SKU_Description  VarChar(30)     NOT NULL,
   Department       VarChar(15)     NULL,
   Buyer            VarChar(20)     NULL,
   CONSTRAINT     SKU_DATA_PK   PRIMARY KEY (SKU)
   );