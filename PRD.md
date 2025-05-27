# Freshstop Application - Product Requirements Document (PRD)

## 1. Introduction

### 1.1 Purpose
The Freshstop application is a Qt-based management system designed to handle user authentication, employee data management, pricelist management, and CSV data import for Freshstop convenience stores associated with Caltex gas stations.

### 1.2 Document Conventions
This document follows standard Product Requirements Document conventions, with sections organized by functional areas and priority levels.

### 1.3 Intended Audience
This document is intended for:
- Development team members
- Project stakeholders
- Quality assurance testers
- System administrators
- Store managers and staff who will use the application

### 1.4 Project Scope
The Freshstop application provides a centralized system for:
- Secure user authentication
- Employee data management
- Pricelist management and viewing
- CSV data import and database integration
- Database table viewing and management

## 2. Overall Description

### 2.1 Product Perspective
The Freshstop application is a standalone desktop application built using the Qt framework. It interfaces with an SQLite database to store and retrieve data about employees, pricelists, suppliers, and other related information for Freshstop convenience stores.

### 2.2 Product Features
- Secure login system with username and password authentication
- Employee data management (add, edit, view)
- Database table browsing functionality
- Pricelist management and viewing
- CSV file import capabilities
- Integration with SQLite database

### 2.3 User Classes and Characteristics
- **Store Administrators**: Access to all features including user management
- **Store Managers**: Access to employee data, pricelists, and inventory management
- **Store Employees**: Limited access to view pricelists and other relevant information

### 2.4 Operating Environment
- **Platform**: Windows desktop
- **Framework**: Qt 5.3.0
- **Database**: SQLite
- **Minimum Requirements**: Compatible with systems that can run Qt applications

### 2.5 Design and Implementation Constraints
- Application must connect to a local SQLite database
- Database file location is fixed at "C:/Freshstop/db/freshstop.db"
- UI design follows Qt widget design patterns
- Application uses standard Qt libraries and components

### 2.6 User Documentation
The application does not currently have comprehensive user documentation. Future versions should include:
- User manual
- Installation guide
- Troubleshooting documentation

### 2.7 Assumptions and Dependencies
- SQLite database must be properly installed and configured
- Required Qt libraries must be available
- Database schema must match the expected structure for the application to function correctly

## 3. System Features

### 3.1 User Authentication System

#### 3.1.1 Description and Priority
The authentication system provides secure access to the application through username and password verification. This is a high-priority feature as it controls access to all other application functions.

#### 3.1.2 Stimulus/Response Sequences
- User launches application and is presented with login screen
- User enters username and password
- System verifies credentials against database
- If valid, user is granted access to main application
- If invalid, error message is displayed

#### 3.1.3 Functional Requirements
- REQ-1: System must validate user credentials against the Login table in the database
- REQ-2: System must prevent unauthorized access
- REQ-3: System must provide appropriate feedback for login success or failure
- REQ-4: Login screen must display Freshstop logo

### 3.2 Employee Data Management

#### 3.2.1 Description and Priority
The employee management module allows for adding, updating, and viewing employee information. This is a medium-priority feature.

#### 3.2.2 Stimulus/Response Sequences
- User navigates to employee management screen
- User can add new employee data (ID, first name, surname)
- User can update existing employee information
- System confirms successful operations with messages

#### 3.2.3 Functional Requirements
- REQ-5: System must allow adding new employee records to the database
- REQ-6: System must allow updating existing employee records
- REQ-7: System must display confirmation messages for successful operations
- REQ-8: System must display error messages when operations fail

### 3.3 Database Table Viewer

#### 3.3.1 Description and Priority
The database table viewer allows users to browse and view various tables in the database. This is a medium-priority feature.

#### 3.3.2 Stimulus/Response Sequences
- User selects a table from dropdown menu
- User clicks "Load Table" button
- System displays the table contents in a grid view

#### 3.3.3 Functional Requirements
- REQ-9: System must display a list of available tables in the database
- REQ-10: System must display table contents in a grid view
- REQ-11: System must support dynamic loading of different tables

### 3.4 Pricelist Management

#### 3.4.1 Description and Priority
The pricelist management module allows users to view and manage product price lists. This is a high-priority feature.

#### 3.4.2 Stimulus/Response Sequences
- User navigates to pricelist screen
- User can load pricelists from database
- User can import pricelists from CSV files

#### 3.4.3 Functional Requirements
- REQ-12: System must display pricelist data from the Supplier table
- REQ-13: System must support CSV file import for pricelists
- REQ-14: System must provide a tabular view of pricelist data

### 3.5 CSV Data Import

#### 3.5.1 Description and Priority
The CSV import functionality allows users to import data from CSV files into the application. This is a medium-priority feature.

#### 3.5.2 Stimulus/Response Sequences
- User navigates to CSV reader
- User selects CSV file from file dialog
- System parses and displays CSV data in a grid
- User can optionally import the CSV data into the database

#### 3.5.3 Functional Requirements
- REQ-15: System must allow selecting CSV files from the file system
- REQ-16: System must parse and display CSV data correctly
- REQ-17: System must handle CSV formatting issues (quotes, delimiters, etc.)
- REQ-18: System must support importing CSV data into the database

## 4. External Interface Requirements

### 4.1 User Interfaces
- **Login Screen**: Username/password fields, login button, status label, Freshstop logo
- **Main Screen**: Employee data fields, save/update buttons, table dropdown, load button, table view
- **Pricelist Screen**: Load from database button, load from CSV button, table view
- **CSV Reader**: File menu for opening CSV files, table view, import to database button

### 4.2 Hardware Interfaces
- Standard keyboard and mouse input
- Display with minimum resolution to accommodate UI elements
- No special hardware requirements

### 4.3 Software Interfaces
- **SQLite Database**: Connection established through Qt's SQL module
- **File System**: Access to read CSV files through Qt's file handling modules

### 4.4 Communications Interfaces
- No external communication interfaces in the current version
- Local database connections only

## 5. Other Nonfunctional Requirements

### 5.1 Performance Requirements
- Application should load and authenticate users within 3 seconds
- Database operations should complete within 2 seconds
- Table views should load data within 3 seconds
- CSV parsing should handle files up to 10MB efficiently

### 5.2 Safety Requirements
- Not applicable for this type of application

### 5.3 Security Requirements
- User passwords should be stored securely in the database
- Application should time out after a period of inactivity (not currently implemented)
- Database connections should be secured

### 5.4 Software Quality Attributes
- **Reliability**: Application should handle database connection errors gracefully
- **Usability**: Interface should be intuitive for store employees
- **Maintainability**: Code structure should allow for easy updates and feature additions
- **Portability**: Application should work on various Windows environments

### 5.5 Business Rules
- Employee data must include ID, first name, and surname
- User authentication requires valid username and password combination
- Pricelist data must be accessible from both database and CSV sources

## 6. Other Requirements

### 6.1 Database Requirements
- SQLite database must be properly configured at C:/Freshstop/db/freshstop.db
- Database must include tables: Login, Supplier, and potentially others
- Login table must include fields for username and password
- Database schema should support employee data and pricelist information

### 6.2 Localization Requirements
- Current version is in English only
- No localization requirements specified at this time

## Appendix A: Glossary

- **Qt**: Cross-platform application framework used to develop this application
- **SQLite**: Self-contained, serverless database engine used to store application data
- **CSV**: Comma-Separated Values, a file format for storing tabular data
- **Pricelist**: List of products with their prices used in Freshstop stores
- **Freshstop**: Convenience store brand associated with Caltex gas stations

## Appendix B: Analysis Models

### Database Schema
- **Login Table**: Contains user authentication data and employee information
- **Supplier Table**: Contains pricelist data from suppliers

### Use Case Model
- User Authentication
- Employee Data Management
- Table Viewing
- Pricelist Management
- CSV Data Import

## Appendix C: Issues List

1. Database path is hardcoded at C:/Freshstop/db/freshstop.db
2. Limited error handling for database connection failures
3. CSV import to database functionality is partially implemented
4. No session timeout or security features beyond basic login
5. Limited user documentation
6. Fixed UI layouts may not scale well to different screen sizes

## Appendix D: Revision History

| Version | Date | Description | Author |
|---------|------|-------------|--------|
| 1.0 | May 27, 2025 | Initial PRD document | Christopher Wells |
