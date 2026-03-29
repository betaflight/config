## Pull-Request requirements

**Mandatory Review for All New Flight Controllers**

- All new flight controllers must undergo the Betaflight review process, regardless of whether they use an existing target.
- Manufacturers may reuse the same target for multiple designs, but each new hardware release must be reviewed before approval.

**Hardware Compliance Requirements**

- All hardware must adhere to the [Manufacturer Design Guidelines](https://betaflight.com/docs/development/manufacturer/manufacturer-design-guidelines).
- Poor hardware designs will not be accepted, as outlined in the [Requirements for the Submission of New and Updated Targets](https://betaflight.com/docs/development/manufacturer/requirements-for-submission-of-targets).
- Adhere to the [Config Target Guidance] https://betaflight.com/docs/development/manufacturer/config-target-guidance
- To avoid costly issues and delays, we strongly encourage consulting with Betaflight developers early in your design process and providing schematics for review **before** producing hardware.

These measures help maintain high standards and ensure compatibility within the Betaflight ecosystem.

If you have any questions or need guidance, feel free to reach out to the Betaflight development team.

**Housekeeping** 
- Pull-Request only from a custom branch, not `master`.
- Replace this text with details of your own.

**Checklist** (✓/✕, or y/n)
- [ ] passed Betaflight team's schematics review
- [ ] passed hardware samples testing
- [ ] follows guidelines
- [ ] follows connector standards
- [ ] flight tested
- [ ] comments/issues resolved
